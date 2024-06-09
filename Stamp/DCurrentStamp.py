from Stamp import ind 

def DCurrentStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  I' + a['@index']
	text += ' */ \n'
	text +='\tauto '+mdl[a['M']]['@name']+a['@index']+' = [] (double t, double is){\n'
	text +='\t\tdouble val;\n'
	
	func_text = mdl[a['M']]['#text']
	args = mdl[a['M']]

	for k in args.keys():
		if k != '@name' and k != '#text':
#			print('In Vt, arg  = ',k.replace("@",""),' and its value =', args[k])		
			func_text = func_text.replace(k.replace("@",""),args[k])
	text +='\t\t'+func_text+'\n\t\treturn val*is;\n\t};\n'

	if 'Group' in a.keys(): Grp = 2

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']


	nl = NumNonLin>0

	if Grp == 2:
		ir = a['Group']
		text += '\trval['+str(ir)+'] = rval['+str(ir)+'] + '+mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
		text += '\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
		ind.add_ind(index,str(ir),str(ir))	
		if nl : text +='\tfvec['+str(ir)+'] -= '+mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
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
			text += '\trval['+P+'] = rval['+P+'] - '+ mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
			if nl : text +='\tfvec['+P+'] += '+ mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
		if int(N) > 0 :
			text += '\trval['+N+'] = rval['+N+'] + '+ mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
			if nl : text +='\tfvec['+N+'] -= '+ mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'

	fl.write(text)
	fv.write(a['@index']+'\t1.0\n')
