#!/usr/bin/env python3
import sys
import xmltodict
from networkx import nx
import matplotlib.pyplot as plt
from LinkActive import *

def color_node(a,b,name):
	if a != '0':
		x = a
	else:
		x = b	
	
	if name == 'Vt':
		y = 0.05
	else:
		y = 0.9

	return (x,y)
		

def net_plot(ff,fs):

	thr = float(input("Please give me the threshold of active nodes: "))

	ActiveEdges = []
	with open(fs,'r') as fstart:
		for line in fstart:
			kl = line.split()
			if link_active(float(kl[3]),thr): ActiveEdges.append((kl[1],kl[2]))


	with open(ff, 'r') as Input:
		doc = xmltodict.parse(Input.read())
	
	Elem = doc['mydocument']['Elements']	
	elist=[e for e in Elem]
	print(elist)
	val_map = {}
	node_list = []


	for name in elist:
		if isinstance(Elem[name],list):
			for i in Elem[name]:
				if i['G'][0]['#text']=='0' or i['G'][1]['#text']=='0' :
					k,h = color_node( i['G'][0]['#text'], i['G'][1]['#text'],name)					
					val_map[k] = h					
				else:
					node_list.append( (i['G'][0]['#text'], i['G'][1]['#text']) )
		else:
			i=Elem[name]
			if i['G'][0]['#text']=='0' or i['G'][1]['#text']=='0' :
				k,h = color_node( i['G'][0]['#text'], i['G'][1]['#text'],name)					
				val_map[k] = h					
			else:
				node_list.append( (i['G'][0]['#text'], i['G'][1]['#text']) )

	G = nx.Graph()
	G.add_edges_from(node_list)

	pos = nx.spring_layout(G)
	values = [val_map.get(node, 0.65) for node in G.nodes()]


#	nx.draw(G, cmap=plt.get_cmap('jet'), node_color=values, node_size=250, with_labels=True,edge_color='0.15')
	nx.draw_networkx_nodes(G,pos, node_color=values, node_size=250, alpha=0.9)
	nx.draw_networkx_edges(G,pos,edgelist=node_list,width=2,edge_color='0.1',alpha=0.6)
	nx.draw_networkx_edges(G,pos,edgelist=ActiveEdges,width=2,edge_color='red',alpha=0.9)
	nx.draw_networkx_labels(G,pos,font_size=12,font_family='sans-serif')
	plt.show()


