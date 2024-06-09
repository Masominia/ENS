from Stamp import ind 

def DiodeStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  D' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	if not hasattr(DiodeStamp, "counter"):
		DiodeStamp.counter = 0  # it doesn't exist yet, so initialize it

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']
	
	if DiodeStamp.counter==0:
		text += '\tdouble Vd;\n'
		text += '\tdouble gn, Geq, Ieq;\n'

	if int(P)>0 and int(N)>0: text += '\tVd = Vx['+P+'] - Vx['+N+'];\n'
	elif int(P)>0: text += '\tVd = Vx['+P+'];\n'
	elif int(N)>0: text += '\tVd = -Vx['+N+'];\n'
	
	comp = {}
	for v ,t in mdl[a['M']].items():
		comp[v.replace("@","").lower()]=t

	text +='\tgn ='+comp['is']+'*exp(Vd/('+comp['mob']+'*'+comp['vt']+'));\n'
	text +='\tGeq = gn/('+comp['mob']+'*'+comp['vt']+');\n'
	text +='\tgn -= '+comp['is']+';\n'
	text +='\tIeq = gn - Geq*Vd;\n'

	if int(P) >0:
		text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq;\n'
		ind.add_ind(index,P,P)
		text +='\trval['+P+'] += -Ieq;\n'
		text +='\tfvec['+P+'] += gn;\n'
	if int(P)>0 and int(N)>0:
		text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq;\n'
		ind.add_ind(index,P,N)
		text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq;\n'
		ind.add_ind(index,N,P)
	if int(N) >0:
		text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq;\n'
		ind.add_ind(index,N,N)
		text +='\trval['+N+'] += Ieq;\n'
		text +='\tfvec['+N+'] += -gn;\n'

	
	fl.write(text)
	DiodeStamp.counter = 1
