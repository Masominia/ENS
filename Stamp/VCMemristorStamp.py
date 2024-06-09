from Stamp import ind 

def VCMemristorStamp(a,mdl,fl,index,NumNonLin,fn,fv):
 
	Grp = 1
	text = '\n /* Elements of  NM' + a['@index']
	text += '*/ \n\n'
	if 'Group' in a.keys(): Grp = 2

	if not hasattr(VCMemristorStamp, "counter"):
		VCMemristorStamp.counter = 0 

	P = a['G'][0]['#text']
	N = a['G'][1]['#text']
	
	if VCMemristorStamp.counter==0:
		text += '\tdouble Un_M, Uo_M, Phi_M, PhiOld_M;\n'
		text += '\tdouble Geq_M, Ieq_M, Sr_M;\n'
		text += '\tdouble xp_M, gq_M,Kh_M,Kp_M;\n'
		text += '\tstatic int tt_M = 0;\n\n'


	ir = a['Group']
	fn.write(str(ir)+'\t'+P+'\t'+N+'\t'+mdl[a['M']]['@Phi0']+'\n')

	text += '\tUn_M = 0.;\n\tUo_M = 0.;\n'
	if int(N)>0: text += '\tUn_M += -Vx['+N+'];\n'
	if int(P)>0: text += '\tUn_M += Vx['+P+'];\n'


	if int(N)>0: text += '\tUo_M += -uxtold['+N+'];\n'
	if int(P)>0: text += '\tUo_M += uxtold['+P+'];\n'

	text +='\tPhiOld_M = uxtold['+str(ir)+'];\n'
	text +='\tPhi_M = Vx['+str(ir)+'];\n'

	func_text = mdl[a['M']]['#text']
	args = mdl[a['M']]

	for k in args.keys():
		if k != '@name' and k != '#text':	
			func_text = func_text.replace(k.replace("@",""),args[k])

	text +='\n\t'+func_text+'\n\n'
	text+='\tGeq_M =Kp_M;\n\tIeq_M = Kh_M - Kp_M*Un_M;\n\tSr_M = Kh_M;\n\n'


	if int(P) >0:
		text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - Geq_M;\n'
		ind.add_ind(index,str(ir),P)
		text +='\tfvec['+P+'] += Vx['+str(ir)+'];\n'
	if int(N) >0:
		text +='\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] + Geq_M;\n'
		ind.add_ind(index,str(ir),N)
		text +='\tfvec['+N+'] += Vx['+str(ir)+'];\n'

	text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
	ind.add_ind(index,str(ir),str(ir))
	text +='\trval['+str(ir)+'] += Ieq_M;\n'
	text +='\tfvec['+str(ir)+'] += Phi_M;\n'

	fl.write(text)
	VCMemristorStamp.counter=1