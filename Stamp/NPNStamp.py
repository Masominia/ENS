from Stamp import ind 

def NPNStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  QN' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	if not hasattr(NPNStamp, "counter"):
		NPNStamp.counter = 0  # it doesn't exist yet, so initialize it
	gt = {}
	
	gt[a['G'][0]['@type']] =  a['G'][0]['#text']
	gt[a['G'][1]['@type']] =  a['G'][1]['#text']
	gt[a['G'][2]['@type']] =  a['G'][2]['#text']

	C = gt['c']
	E = gt['e']
	B = gt['b']

	if NPNStamp.counter==0:
		text += '\tdouble Vbe_n, Vbc_n;\n'
		text += '\tdouble gee_n, gec_n, gce_n, gcc_n, Ie_n, Ic_n;\n'
		text += '\tdouble ie_n, ic_n;\n'

	if int(C)>0 and int(B)>0: text += '\tVbc_n = Vx['+B+'] - Vx['+C+'];\n'
	elif int(B)>0: text += '\tVbc_n =  Vx['+B+'];\n'
	elif int(C)>0: text += '\tVbc_n = -Vx['+C+'];\n'

	if int(E)>0 and int(B) >0: text += '\tVbe_n = Vx['+B+'] - Vx['+E+'];\n'
	elif int(B)>0: text += '\tVbe_n = Vx['+B+'];\n'
	elif int(E)>0: text += '\tVbe_n = -Vx['+E+'];\n'

	cp = {}
	for v ,t in mdl[a['M']].items():
		cp[v.replace("@","").lower()]=t

	text += '\tgee_n = ('+cp['ies']+'/'+cp['vte']+')*exp(Vbe_n/'+cp['vte']+');\n'
	text += '\tgec_n = '+cp['ar']+'*('+cp['ics']+'/'+cp['vtc']+')*exp(Vbc_n/'+cp['vtc']+');\n'
	text += '\tgce_n = '+cp['af']+'*('+cp['ies']+'/'+cp['vte']+')*exp(Vbe_n/'+cp['vte']+');\n'
	text += '\tgcc_n = ('+cp['ics']+'/'+cp['vtc']+')*exp(Vbc_n/'+cp['vtc']+');\n'

	text += '\tie_n = -'+cp['ies']+'*(exp(Vbe_n/'+cp['vte']+')-1)+'+cp['ar']+'*'+cp['ics']+'*(exp(Vbc_n/'+cp['vtc']+')-1);\n'
	text += '\tic_n = '+cp['af']+'*'+cp['ies']+'*(exp(Vbe_n/'+cp['vte']+')-1)- '+cp['ics']+'*(exp(Vbc_n/'+cp['vtc']+')-1);\n'

	text +='\tIe_n = ie_n + gee_n*Vbe_n - gec_n*Vbc_n;\n'
	text +='\tIc_n = ic_n - gce_n*Vbe_n + gcc_n*Vbc_n;\n'

	if int(E) >0:
		text +='\tmna['+E+']('+E+') = mna['+E+']['+E+'] + gee_n;\n'
		ind.add_ind(index,E,E)
		text +='\trval['+E+'] += -Ie_n;\n'
		text +='\tfvec['+E+'] += ie_n;\n'
	if int(C) >0:
		text +='\tmna['+C+']('+C+') = mna['+C+']['+C+'] + gcc_n;\n'
		ind.add_ind(index,C,C)
		text +='\trval['+C+'] += -Ic_n;\n'
		text +='\tfvec['+C+'] += ic_n;\n'
	if int(B) >0:
		text +='\tmna['+B+']('+B+') = mna['+B+']['+B+'] + gcc_n+gee_n-gce_n-gec_n;\n'
		ind.add_ind(index,B,B)
		text +='\trval['+B+'] += (Ie_n+Ic_n);\n'
		text +='\tfvec['+B+'] += -(ie_n+ic_n);\n'
	if int(E) >0 and int(C) >0:
		text +='\tmna['+E+']('+C+') = mna['+E+']['+C+'] - gec_n;\n'
		ind.add_ind(index,E,C)
		text +='\tmna['+C+']('+E+') = mna['+C+']['+E+'] - gce_n;\n'
		ind.add_ind(index,C,E)
	if int(E) >0 and int(B) >0:
		text +='\tmna['+E+']('+B+') = mna['+E+']['+B+'] + (gec_n-gee_n);\n'
		ind.add_ind(index,E,B)
		text +='\tmna['+B+']('+E+') = mna['+B+']['+E+'] + (gce_n-gee_n);\n'
		ind.add_ind(index,B,E)
	if int(B) >0 and int(C) >0:
		text +='\tmna['+B+']('+C+') = mna['+B+']['+C+'] + (gec_n-gcc_n);\n'
		ind.add_ind(index,B,C)
		text +='\tmna['+C+']('+B+') = mna['+C+']['+B+'] + (gce_n-gcc_n);\n'
		ind.add_ind(index,C,B)

	fl.write(text)
	NPNStamp.counter = 1	
