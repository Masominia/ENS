from Stamp import ind 

def DVoltageStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  V' + a['@index']
	text += ' */ \n'
	text +='\tauto '+mdl[a['M']]['@name']+a['@index']+' = [] (double t, double vs){\n'
	text +='\t\tdouble val;\n'
	
	func_text = mdl[a['M']]['#text']
	args = mdl[a['M']]

	for k in args.keys():
		if k != '@name' and k != '#text':
#			print('In Vt, arg  = ',k.replace("@",""),' and its value =', args[k])		
			func_text = func_text.replace(k.replace("@",""),args[k])
	text +='\t\t'+func_text+'\n\t\treturn val*vs;\n\t};\n'

	if 'Group' in a.keys(): Grp = 2

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']

	ir = a['Group']
	nl = NumNonLin>0

	text += '\trval['+str(ir)+'] = rval['+str(ir)+'] + '+mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
	if nl : text +='\tfvec['+str(ir)+'] -= '+mdl[a['M']]['@name']+a['@index']+'(tm,Vs['+a['@index']+'])'+';\n'
	if int(P) > 0 :
		text += '\tmna['+P+']('+str(ir)+') = mna['+P+']['+str(ir)+'] + 1.;\n'
		if nl : text +='\tfvec['+P+'] +=  Vx['+str(ir)+'];\n'
		ind.add_ind(index,P,str(ir))	
		text += '\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] + 1.;\n'		
		if nl : text +='\tfvec['+str(ir)+'] +=  Vx['+P+'];\n'
		ind.add_ind(index,str(ir),P)
	if int(N) > 0 :
		text += '\tmna['+N+']('+str(ir)+') = mna['+N+']['+str(ir)+'] - 1.;\n'	
		if nl : text +='\tfvec['+N+'] -=  Vx['+str(ir)+'];\n'
		ind.add_ind(index,N,str(ir))
		text += '\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] - 1.;\n'		
		if nl : text +='\tfvec['+str(ir)+'] -=  Vx['+N+'];\n'
		ind.add_ind(index,str(ir),N)


	fl.write(text)
	fv.write(a['@index']+'\t1.0\n')

