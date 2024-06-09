from Stamp import ind 

def ResistorStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  R' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']

	Val = a['Val']
#	Val += '.'
	nl = NumNonLin>0

	if Grp == 2:
		ir = a['Group']
		if int(P) > 0 :
			text += '\tmna['+P+']('+str(ir)+') = mna['+P+']['+str(ir)+'] + 1.;\n'	
			ind.add_ind(index,P,str(ir))
			if nl : text +='\tfvec['+P+'] +=  Vx['+str(ir)+'];\n'
			text += '\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] + 1.;\n'		
			ind.add_ind(index,str(ir),P)
			if nl : text +='\tfvec['+str(ir)+'] += Vx['+P+'];\n'
		if int(N) > 0 :
			text += '\tmna['+N+']('+str(ir)+') = mna['+N+']['+str(ir)+'] - 1.;\n'	
			ind.add_ind(index,N,str(ir))
			if nl : text +='\tfvec['+N+'] -=  Vx['+str(ir)+'];\n'
			text += '\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] - 1.;\n'		
			ind.add_ind(index,str(ir),N)
			if nl : text +='\tfvec['+str(ir)+'] -=  Vx['+N+'];\n'
		text += '\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] - '+Val+';\n'		
		ind.add_ind(index,str(ir),str(ir))
		if nl : text +='\tfvec['+str(ir)+'] -= '+Val+'*Vx['+str(ir)+'];\n'
	else:

		if int(P) >0:
			text += '\tmna['+P+']('+P+') = mna['+P+']['+P+'] + 1./'+Val+';\n'	
			ind.add_ind(index,P,P)
			if nl : text +='\tfvec['+P+'] +=  Vx['+P+']/'+Val+';\n'
		if int(N) >0:
			text += '\tmna['+N+']('+N+') = mna['+N+']['+N+'] + 1./'+Val+';\n'	
			ind.add_ind(index,N,N)
			if nl : text +='\tfvec['+N+'] +=  Vx['+N+']/'+Val+';\n'
		if int(P)>0 and int(N)>0:
			text += '\tmna['+P+']('+N+') = mna['+P+']['+N+'] - 1./'+Val+';\n'	
			ind.add_ind(index,P,N)
			if nl : text +='\tfvec['+P+'] -= Vx['+N+']/'+Val+';\n'
			text += '\tmna['+N+']('+P+') = mna['+N+']['+P+'] - 1./'+Val+';\n'	
			ind.add_ind(index,N,P)
			if nl : text +='\tfvec['+N+'] -= Vx['+P+']/'+Val+';\n'
	fl.write(text)
