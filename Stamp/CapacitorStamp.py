from Stamp import ind

def CapacitorStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  C' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']

	Val = a['Val']
	nl = NumNonLin>0

	if Grp == 2:
		ir = a['Group']
		if int(P) > 0 :
			text += '\tmna['+P+']('+str(ir)+') = mna['+P+']['+str(ir)+'] + 1.;\n'
			ind.add_ind(index,P,str(ir))	
			text += '\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] + idt*'+Val+';\n'	
			ind.add_ind(index,str(ir),P)
			text += '\trval['+str(ir)+'] = rval['+str(ir)+'] - idt*'+Val+'*(uxtold['+P+']);\n'
		
		if int(N) > 0 :
			text += '\tmna['+N+']('+str(ir)+') = mna['+N+']['+str(ir)+'] - 1.;\n'	
			ind.add_ind(index,N,str(ir))
			text += '\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] - idt*'+Val+';\n'		
			ind.add_ind(index,str(ir),N)
			text += '\trval['+str(ir)+'] = rval['+str(ir)+'] + idt*'+Val+'*(uxtold['+N+']);\n'
		text += '\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] - 1.;\n'		
		ind.add_ind(index,str(ir),str(ir))


	else:

		if int(P) >0:
			text += '\tmna['+P+']('+P+') = mna['+P+']['+P+'] + idt*'+Val+';\n'	
			ind.add_ind(index,P,P)
			text += '\trval['+P+'] = rval['+P+'] + idt*'+Val+'*(uxtold['+P+'] - uxtold['+N+']);\n'
			if nl : text +='\tfvec['+P+'] +=  idt*'+Val+'*(Vx['+P+']-uxtold['+P+']);\n'
		if int(N) >0:
			text += '\tmna['+N+']('+N+') = mna['+N+']['+N+'] + idt*'+Val+';\n'	
			ind.add_ind(index,N,N)
			text += '\trval['+N+'] = rval['+N+'] + idt*'+Val+'*(uxtold['+N+'] - uxtold['+P+']);\n'
			if nl : text +='\tfvec['+N+'] +=  idt*'+Val+'*(Vx['+N+']-uxtold['+N+']);\n'
		if int(P)>0 and int(N)>0:
			text += '\tmna['+P+']('+N+') = mna['+P+']['+N+'] - idt*'+Val+';\n'	
			ind.add_ind(index,P,N)
			if nl : text +='\tfvec['+P+'] -=  idt*'+Val+'*(Vx['+N+']-uxtold['+N+']);\n'
			text += '\tmna['+N+']('+P+') = mna['+N+']['+P+'] - idt*'+Val+';\n'	
			ind.add_ind(index,N,P)
			if nl : text +='\tfvec['+N+'] -=  idt*'+Val+'*(Vx['+P+']-uxtold['+P+']);\n'
	fl.write(text)
