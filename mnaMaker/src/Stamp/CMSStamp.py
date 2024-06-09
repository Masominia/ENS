from Stamp import ind
def CMSStamp(a,mdl,fl,index,NumNonLin,fn,fv):

    Grp=1
    text = '\n /* Elements of CMS' + a['@index']
    text += '*/\n\n'
    if 'Group' in a.keys(): Grp = 2

    if not hasattr(CMSStamp, "counter"):
        CMSStamp.counter = 0
    
    P = a['G'][0]['#text']
    N = a['G'][1]['#text']

# avoiding rewrite, in case of multiple Memristor
    if CMSStamp.counter==0:
        text += '\tdouble Un_CM, Uo_CM, Omegaold_CM, Omegaxold_CM, Omega_CM;\n'
        text += '\tdouble Geq_CM, Ieq_CM, Sr_CM, Sr_CMO, GGeq_CM, IIeq_CM, Kpi_CM, Ki_CM, Kv_CM,Kpv_CM, RR, Jw, Jv, Fwv;\n'
        text += '\tstatic int tt_CM = 0;\n\n'
    
    ir = a['Group']
    fn.write(str(ir)+'\t'+P+'\t'+N+'\t'+mdl[a['M']]['@Q0']+'\n')

    text += '\tUn_CM = 0.;\n\tUo_CM = 0.;\n'
    if int(N)>0: text += '\tUn_CM += -Vx['+N+'];\n'
    if int(P)>0: text += '\tUn_CM += Vx['+P+'];\n'


    if int(N)>0: text += '\tUo_CM += -uxtold['+N+'];\n'
    if int(P)>0: text += '\tUo_CM += uxtold['+P+'];\n'

    text +='\tOmegaxold_CM = 0.;\n\tOmegaold_CM = 0.;\n\tOmega_CM = 0;\n\n'

    text +='\tOmegaxold_CM = uxtold['+str(ir)+'];\n'

    text +='\tOmegaold_CM = Vx['+str(ir)+'];\n\n\n'


    func_text = mdl[a['M']]['#text']
    args = mdl[a['M']]

    for k in args.keys():
    	if k != '@name' and k != '#text':
    		func_text = func_text.replace(k.replace("@",""),args[k])

    text +='\n\t'+func_text+'\n\n'

    text +='\tIIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);\n'
    text +='\tGGeq_CM = -1*Kpi_CM;\n'  
    text +='\tOmega_CM = IIeq_CM+(GGeq_CM*Un_CM);\n'
    text +='\tSr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;\n\n'


    text +='\tGeq_CM = (1./RR) + Kpv_CM;\n'
    text +='\tIeq_CM = Kv_CM + (Kpv_CM * Un_CM);\n'
    text +='\tSr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;\n\n'




    if int(P) >0:
        text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - GGeq_CM;\n'
        ind.add_ind(index,str(ir),P)
        text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_CM;\n'
        ind.add_ind(index,P,P)
        text +='\trval['+P+'] += -Ieq_CM;\n'
        text +='\tfvec['+P+'] += Vx['+P+'];\n'
#        text +='\tfvec['+P+'] += Sr_CM;\n'
    if int(P)>0 and int(N)>0:
        text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq_CM;\n'
        ind.add_ind(index,P,N)
        text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq_CM;\n'
        ind.add_ind(index,N,P)
    if int(N) >0:
        text +='\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] + GGeq_CM;\n'
        ind.add_ind(index,str(ir),N)
        text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq_CM;\n'
        ind.add_ind(index,N,N)
        text +='\trval['+N+'] += Ieq_CM;\n'
        text +='\tfvec['+N+'] += -Vx['+N+'];\n'
#        text +='\tfvec['+N+'] += -Sr_CM;\n'

    text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
    ind.add_ind(index,str(ir),str(ir))
    text +='\trval['+str(ir)+'] += IIeq_CM;\n'
    text +='\tfvec['+str(ir)+'] += Sr_CMO;\n'

    fl.write(text)
    CMSStamp.counter=1