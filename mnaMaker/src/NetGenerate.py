#! /usr/bin/python3

import sh
import sys
import networkx as nx
sys.path.append('src')
from src import xmltodict

def FileGen(net,source,Snum,ns,link,link_model,Rvalue,Rnum,hub_list,path,tinit):

	res = open(path+'/temp/resist.inp','w')
#	vs  = open(path+'/temp/volt.inp','w')

	op = open('temp.xml','w')
	op.write('<mydocument>\n  <Elements>\n')

	index = 1
	for k in ns:
		op.write('    <Vt index="'+str(index)+'">\n')
		op.write('\t<G index="1">'+str(k)+'</G>\n\t<G index="2">0</G>\n')
		op.write('\t<M>'+source+'</M>\n')
		op.write('\t<Group>G2</Group>\n')
		op.write('    </Vt>\n')

#		vs.write(str(index)+'\t1.0\n')
		index +=1
		if index > Snum: break	
	index = 1
	for k in net.keys():
		for v in net[k]:
			if v > k: 
				op.write('    <'+link+' index="'+str(index)+'">\n')
				op.write('\t<G index="1">'+str(k)+'</G>\n\t<G index="2">'+str(v)+'</G>\n')
				op.write('\t<M>'+link_model+'</M>\n')
				op.write('\t<Group>G2</Group>\n')
				op.write('    </'+link+'>\n')
				index += 1
	index = 1

	for k in hub_list:
		op.write('    <R index="'+str(index)+'">\n')
		op.write('\t<G index="1">'+str(k)+'</G>\n\t<G index="2">0</G>\n')
		op.write('\t<Val>'+Rvalue+'['+str(index)+']'+'</Val>\n')
		op.write('\t<Group>G2</Group>\n')
		op.write('    </R>\n')

		res.write(str(index)+'\t'+tinit+'\n')
		index += 1
		if index > Rnum: break

	op.write('  </Elements>\n</mydocument>')

def EdgeNodes(G,n):
#
#	Retrun the farest nodes from node n 
#
	ns = []
	p = nx.shortest_path(G,n)
	v_max = 0
	for k ,v  in p.items():
		if len(v) > v_max: v_max = len(v)
#		print(k,v,len(v))
#	print('maximum distance is: ',v_max)
	
	for k,v in p.items():
		if len(v) == v_max: ns.append(k)

	return ns

def plot(G):

	import matplotlib.pyplot as plt


	nx.draw(G)
	plt.show()	

def SortList(ls, dls):


	N = len(ls)
	M = len(dls)
	tdls = []

	for i in range(0,M):	tdls.append(dls[i])

	i = 0
	for k in tdls:
		
		i = i +1
		for j in range(0,N):
			if ls[j] > k: 
				ls[j] = ls[j] -1
		for l in range(i,M):	tdls[l] = tdls[l] - 1
	return ls

def SortDic(dic,dls,N):

	for j in dic.keys():
		dic[j] = SortList(dic[j], dls)
#	N = len(dic)
	M = len(dls)
	tdls = []
	for i in range(0,M):	tdls.append(dls[i])

	i = 0
	for k in tdls:
		i = i+1
		for j in range(0,N+1):
			if j in dic.keys() and j > k: dic[j-1] = dic.pop(j)
		for l in range(i,M):	tdls[l] = tdls[l] - 1
#		print('reduced tdls = ',tdls)
		
		##for k,v in dic.items():
		##	print(k,v)
	return dic

def NetGen(size, link, init_deg,linkKind,linkModel,sources,Snum,Rvalue,Rnum,wpath,tinit,method):
	Net = {}
	run = sh.Command('./NetGen')
	s = run(size,link,init_deg)
#	print(s)
	f = str(s).split('\n')
	f.pop()
	for k in f:
		Net[int(k.split('\t')[0])] =k.split('\t')[1]
#	for k in Net.keys():
#		print(k,Net[k].split(),len(Net[k].split()))

	IN = len(Net)
#	print(IN)
	CorNet = {}	
	for k in Net.keys(): CorNet[k] = []


	for k in Net.keys():
		for j in Net[k].split():
			CorNet[k].append(int(j))


	for k in CorNet.keys():
		CorNet[k] = sorted(CorNet[k])
	N = len(CorNet)
#	print("size of CorNet is: ",N)

	del_list = []
	for k in CorNet.keys():
		if len(CorNet[k]) == 0: del_list.append(k)
	del_list = sorted(del_list)

	for j in del_list: 
		CorNet.pop(j)


#	for k in CorNet.keys():
#		print(k,CorNet[k])
#	print("Number of removed zero items in CorNet is: ",N -len(CorNet))		
#	print('Removing list is: ',del_list)

	SortDic(CorNet,del_list,IN)
	NodeDegree = {}
	for k in CorNet.keys():
#		print(k,CorNet[k],len(CorNet[k]))
		NodeDegree[k]=len(CorNet[k])

#	print("Nodes' Degree are: ",NodeDegree)
	ND_Sorted = []  # Sorted nodes based on their degree

	for w in sorted(NodeDegree, key=NodeDegree.get, reverse=True):
		ND_Sorted.append(w)

#	print("Seoted nodes based on degree is:",ND_Sorted)

	G = nx.Graph()

	for k in CorNet.keys():
		for v in CorNet[k]:
			if v>k: G.add_edge(k,v)

#	plot(G)

	ns = []	

	if method == 'reg':
		if Rnum>0 :
			kp = 0
			for s in range(0,Rnum):
				EDS =  EdgeNodes(G,ND_Sorted[s])
				for w in EDS:
					if w not in ns:
						ns.append(w)
						kp +=1
				if kp >=Rnum: break
			print('Rnum = ',Rnum,' kp = ', kp)
			if len(ns)<=Rnum: 
				print('Not enough tail nodes has been found')
		else:
			EDS =  EdgeNodes(G,ND_Sorted[0])
			print('EDS = ',EDS,' zero node = ',ND_Sorted[0])
			for w in EDS:
				if w not in ns:
					ns.append(w)
			print('ns = ',ns)
			Rnum = len(ns)
		FileGen(CorNet,sources,Snum,ND_Sorted,linkKind,linkModel,Rvalue, Rnum, ns,wpath,tinit)	

	elif method == 'opp':
		if Snum>0 : 
			kp = 0
			for s in range(0,Snum):
				EDS =  EdgeNodes(G,ND_Sorted[s])
				for w in EDS:
					if w not in ns:
						ns.append(w)
						kp +=1
				if kp >=Snum: break
			print('Snum = ',Snum,' kp = ', kp)
			if len(ns)<=Snum: 
				print('Not enough tail nodes has been found')
		else:
			EDS =  EdgeNodes(G,ND_Sorted[0])
			for w in EDS:
				if w not in ns:
					ns.append(w)
			Snum = len(ns)
		FileGen(CorNet,sources,Snum,ns,linkKind,linkModel,Rvalue, Rnum, ND_Sorted,wpath,tinit)	

	else:
		print('wrong network construction method  is defined')
		

	


#	print('farest nodes from ',ND_Sorted[0],' are: ',ns)

#	print('average clustering of this network is: ',nx.average_clustering(G))
	




	with open('temp.xml', 'r') as input:
		netdoc = xmltodict.parse(input.read())


	return netdoc['mydocument']['Elements']




