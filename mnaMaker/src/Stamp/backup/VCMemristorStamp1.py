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
#	text +='\tQz_M = '+mdl[a['M']]['@Q0']+';\n'
#	text += '\tQz_M = Ch0['+str(ir)+'];\n'
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
#			print('In Vt, arg  = ',k.replace("@",""),' and its value =', args[k])		
			func_text = func_text.replace(k.replace("@",""),args[k])

	text +='\n\t'+func_text+'\n\n'

#	text+='\tGeq_M =Kp_M;\n\tIeq_M = Kh_M - Kp_M*Un_M;\n\tSr_M = 0.1*(idt*(Phi_M-PhiOld_M)*Geq_M + Ieq_M);\n\n'
	text+='\tGeq_M =Kp_M;\n\tIeq_M = Kh_M - Kp_M*Un_M;\n\tSr_M = Kh_M;\n\n'


	if int(P) >0:
		text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_M;\n'
		ind.add_ind(index,P,P)
		text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - Delt;\n'
		ind.add_ind(index,str(ir),P)
		text +='\trval['+P+'] += -(Ieq_M) ;\n'
		text +='\tfvec['+P+'] += Sr_M;\n'
	if int(P)>0 and int(N)>0:
		text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq_M;\n'
		ind.add_ind(index,P,N)
		text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq_M;\n'
		ind.add_ind(index,N,P)
	if int(N) >0:
		text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq_M;\n'
		ind.add_ind(index,N,N)
		text +='\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] + Delt;\n'
		ind.add_ind(index,str(ir),N)
		text +='\trval['+N+'] += (Ieq_M);\n'
		text +='\tfvec['+N+'] += -(Sr_M);\n'

	text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
	ind.add_ind(index,str(ir),str(ir))
	text +='\trval['+str(ir)+'] += PhiOld_M;\n'
	text +='\tfvec['+str(ir)+'] += -Delt*Un_M + Phi_M - PhiOld_M;\n'

	fl.write(text)
	VCMemristorStamp.counter=1


