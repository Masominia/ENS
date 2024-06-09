from Stamp import ind 

def CurrentStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  I' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']

	Val = a['Val']
	nl = NumNonLin>0
	
	if Grp == 2:
		ir = a['Group']
		text += '\trval['+str(ir)+'] = rval['+str(ir)+'] + '+Val+';\n'
		text += '\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
		ind.add_ind(index,str(ir),str(ir))	
		if nl : text +='\tfvec['+str(ir)+'] -= '+Val+';\n'
		if int(P) > 0 :
			text += '\tmna['+P+']('+str(ir)+') = mna['+P+']['+str(ir)+'] + 1.;\n'
			if nl : text +='\tfvec['+P+'] +=  Vx['+str(ir)+'];\n'
			ind.add_ind(index,P,str(ir))	
		if int(N) > 0 :
			text += '\tmna['+N+']('+str(ir)+') = mna['+N+']['+str(ir)+'] - 1.;\n'	
			if nl : text +='\tfvec['+N+'] -=  Vx['+str(ir)+'];\n'
			ind.add_ind(index,N,str(ir))
	else:

		if int(P) > 0 :
			text += '\trval['+P+'] = rval['+P+'] - '+Val+';\n'
			if nl : text +='\tfvec['+P+'] += '+Val+';\n'
		if int(N) > 0 :
			text += '\trval['+N+'] = rval['+N+'] + '+Val+';\n'
			if nl : text +='\tfvec['+N+'] -= '+Val+';\n'

	fl.write(text)
	
