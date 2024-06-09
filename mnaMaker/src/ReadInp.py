import xmltodict
import NetGenerate as ng

def ReadInput(self,WorkDir,fl_xml):

	CRT = False

	with open(fl_xml, 'r') as input:
		doc = xmltodict.parse(input.read())


	mydict = doc['mydocument']

	if 'Minion' in mydict:
		self.crt_name = mydict['Minion']
		CRT = True

	self.Elem = mydict['Elements']
	self.Model = mydict['Models']
	self.Simu = mydict['Simulations']


	if 'Network' in mydict:
		Net = mydict['Network']

#		sources = {}
#		for y in Net['Snode'] : sources[y['@index']] = y['#text']
		net_elem = {}
		net_elem = ng.NetGen(Net['Nodes'], Net['Edges'], Net['Init_degree'],Net['Link'],Net['LinkModel'],Net['Snode'],int(Net['Snum']),Net['Tail'],int(Net['Rnum']),WorkDir,Net['Tinit'],Net['Method'])
#		print(net_elem)
		self.Elem.update(net_elem)

	if 'Null' in self.Elem: self.Elem.pop('Null')


	NonLinList = ['D', 'QN', 'QP', 'CCM', 'VCM', 'NC']

	elist=[e for e in self.Elem]
	print(elist)
	Num = 0
	self.NumElem = 0
	self.NumNonLinElem = 0

	for name in elist:
		if isinstance(self.Elem[name],list):
			for i in self.Elem[name]:
				self.NumElem +=1	
				if name in NonLinList: self.NumNonLinElem += 1
				for k in i['G']:
					if int(k['#text']) > Num : Num = int(k['#text'])
		else:
			self.NumElem +=1
			if name in NonLinList: self.NumNonLinElem += 1
			i=self.Elem[name]
#			print('i is:\n',i)
			for k in i['G']:
				if int(k['#text']) > Num : Num = int(k['#text'])
#	print("Number of nodes in "+fl_xml+" is equall to "+str(Num))
	self.NumNode = Num 
	Num +=1
	self.NumG2 = 0
	for name in elist:
		if isinstance(self.Elem[name],list):
			for i in self.Elem[name]:
				if 'Group' in i.keys(): 
					i['Group'] = Num
					Num += 1
					self.NumG2 += 1
		else:
			i=self.Elem[name]
			if 'Group' in i.keys(): 
				i['Group'] = Num
				Num += 1
				self.NumG2 += 1
	return CRT		





