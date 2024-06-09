from Stamp import ind 

def PNPStamp(a,mdl,fl,index,NumNonLin,fn,fv):
	
	Grp = 1
	text = '\n /* Elements of  QP' + a['@index']
	text += '*/ \n'
	if 'Group' in a.keys(): Grp = 2

	if not hasattr(PNPStamp, "counter"):
		PNPStamp.counter = 0  # it doesn't exist yet, so initialize it
	gt = {}
	
	gt[a['G'][0]['@type']] =  a['G'][0]['#text']
	gt[a['G'][1]['@type']] =  a['G'][1]['#text']
	gt[a['G'][2]['@type']] =  a['G'][2]['#text']

	C = gt['c']
	E = gt['e']
	B = gt['b']

	if PNPStamp.counter==0:
		text += '\tdouble Vbe_p, Vbc_p;\n'
		text += '\tdouble gee_p, gec_p, gce_p, gcc_p, Ie_p, Ic_p;\n'
		text += '\tdouble ie_p, ic_p;\n'

	if int(C)>0 and int(B)>0: text += '\tVbc_p = Vx['+C+'] - Vx['+B+'];\n'
	elif int(B)>0: text += '\tVbc_p =  -Vx['+B+'];\n'
	elif int(C)>0: text += '\tVbc_p = Vx['+C+'];\n'

	if int(E)>0 and int(B) >0: text += '\tVbe_p = Vx['+E+'] - Vx['+B+'];\n'
	elif int(B)>0: text += '\tVbe_p = -Vx['+B+'];\n'
	elif int(E)>0: text += '\tVbe_p = Vx['+E+'];\n'

	cp = {}
	for v ,t in mdl[a['M']].items():
		cp[v.replace("@","").lower()]=t

	text += '\tgee_p = ('+cp['ies']+'/'+cp['vte']+')*exp(Vbe_p/'+cp['vte']+');\n'
	text += '\tgec_p = '+cp['ar']+'*('+cp['ics']+'/'+cp['vtc']+')*exp(Vbc_p/'+cp['vtc']+');\n'
	text += '\tgce_p = '+cp['af']+'*('+cp['ies']+'/'+cp['vte']+')*exp(Vbe_p/'+cp['vte']+');\n'
	text += '\tgcc_p = ('+cp['ics']+'/'+cp['vtc']+')*exp(Vbc_p/'+cp['vtc']+');\n'

	text += '\tie_p = -'+cp['ies']+'*(exp(Vbe_p/'+cp['vte']+')-1)+'+cp['ar']+'*'+cp['ics']+'*(exp(Vbc_p/'+cp['vtc']+')-1);\n'
	text += '\tic_p = '+cp['af']+'*'+cp['ies']+'*(exp(Vbe_p/'+cp['vte']+')-1)- '+cp['ics']+'*(exp(Vbc_p/'+cp['vtc']+')-1);\n'

	text +='\tIe_p = ie_p + gee_p*Vbe_p - gec_p*Vbc_p;\n'
	text +='\tIc_p = ic_p - gce_p*Vbe_p + gcc_p*Vbc_p;\n'

	if int(E) >0:
		text +='\tmna['+E+']('+E+') = mna['+E+']['+E+'] + gee_p;\n'
		ind.add_ind(index,E,E)
		text +='\trval['+E+'] += -Ie_p;\n'
		text +='\tfvec['+E+'] += ie_p;\n'
	if int(C) >0:
		text +='\tmna['+C+']('+C+') = mna['+C+']['+C+'] + gcc_p;\n'
		ind.add_ind(index,C,C)
		text +='\trval['+C+'] += -Ic_p;\n'
		text +='\tfvec['+C+'] += ic_p;\n'
	if int(B) >0:
		text +='\tmna['+B+']('+B+') = mna['+B+']['+B+'] + gcc_p+gee_p-gce_p-gec_p;\n'
		ind.add_ind(index,B,B)
		text +='\trval['+B+'] += (Ie_p+Ic_p);\n'
		text +='\tfvec['+B+'] += -(ie_p+ic_p);\n'
	if int(E) >0 and int(C) >0:
		text +='\tmna['+E+']('+C+') = mna['+E+']['+C+'] - gec_p;\n'
		ind.add_ind(index,E,C)
		text +='\tmna['+C+']('+E+') = mna['+C+']['+E+'] - gce_p;\n'
		ind.add_ind(index,C,E)
	if int(E) >0 and int(B) >0:
		text +='\tmna['+E+']('+B+') = mna['+E+']['+B+'] + (gec_p-gee_p);\n'
		ind.add_ind(index,E,B)
		text +='\tmna['+B+']('+E+') = mna['+B+']['+E+'] + (gce_p-gee_p);\n'
		ind.add_ind(index,B,E)
	if int(B) >0 and int(C) >0:
		text +='\tmna['+B+']('+C+') = mna['+B+']['+C+'] + (gec_p-gcc_p);\n'
		ind.add_ind(index,B,C)
		text +='\tmna['+C+']('+B+') = mna['+C+']['+B+'] + (gce_p-gcc_p);\n'
		ind.add_ind(index,C,B)

	fl.write(text)
	PNPStamp.counter = 1	
