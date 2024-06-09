from Stamp import ind 

def NonLinCapStamp(a,mdl,fl,index,NumNonLin,fn,fv):
 
	Grp = 1
	text = '\n /* Elements of  NonLinearCapacitor' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	if not hasattr(NonLinCapStamp, "counter"):
		NonLinCapStamp.counter = 0 

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']
	
	if NonLinCapStamp.counter==0:
		text += '\tdouble Un_nc, Uo_nc, Qz_nc;\n'
		text += '\tdouble Geq_nc, Ieq_nc;\n'
		text += '\tdouble Cu_nc, Gc_nc, Gpc_nc;\n'
		text += '\tstatic int tt_nc = 0;\n\n'

	if Grp==2:ir = a['Group']
	text +='\tQz_nc = '+mdl[a['M']]['@Qz']+';\n'
#	text += '\tif(tt_M==0) {\n'
#	text += '\t\tuxtold['+str(ir)+'] = Qz_M; tt_M =1;\n\t}\n'

	text += '\tUn_nc = 0.;\n\tUo_nc = 0.;\n'
	if int(N)>0: text += '\tUn_nc += -Vx['+N+'];\n'
	if int(P)>0: text += '\tUn_nc += Vx['+P+'];\n'

	if int(N)>0: text += '\tUo_nc += -uxtold['+N+'];\n'
	if int(P)>0: text += '\tUo_nc += uxtold['+P+'];\n'

	func_text = mdl[a['M']]['#text']
	args = mdl[a['M']]

	for k in args.keys():
		if k != '@name' and k != '#text':
#			print('In Vt, arg  = ',k.replace("@",""),' and its value =', args[k])		
			func_text = func_text.replace(k.replace("@",""),args[k])

	text +='\n\t'+func_text+'\n\n'
#	text +='\tSr_nc = Cu_nc*(Un_nc-Uo_nc)/Delt;\n'

	if int(P) >0:
		text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_nc;\n'
		ind.add_ind(index,P,P)
		text +='\trval['+P+'] += -Ieq_nc;\n'
#		text +='\tfvec['+P+'] += Sr_nc;\n'
	if int(P)>0 and int(N)>0:
		text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq_nc;\n'
		ind.add_ind(index,P,N)
		text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq_nc;\n'
		ind.add_ind(index,N,P)
	if int(N) >0:
		text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq_nc;\n'
		ind.add_ind(index,N,N)
		text +='\trval['+N+'] += Ieq_nc;\n'
#		text +='\tfvec['+N+'] -= Sr_nc;\n'
	
	if int(P) >0:	
		text +='\tfvec['+P+'] += Cu_nc*idt*(Vx['+P+']-uxtold['+P+']);\n'
	if int(N) >0:
		text +='\tfvec['+N+'] += Cu_nc*idt*(Vx['+N+']-uxtold['+N+']);\n'
	if int(P)>0 and int(N)>0:
		text +='\tfvec['+P+'] -= Cu_nc*idt*(Vx['+N+']-uxtold['+N+']);\n'
		text +='\tfvec['+N+'] -= Cu_nc*idt*(Vx['+P+']-uxtold['+P+']);\n'
	
	fl.write(text)
	NonLinCapStamp.counter=1





