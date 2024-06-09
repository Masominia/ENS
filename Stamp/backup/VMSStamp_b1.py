from Stamp import ind
def VMSStamp(a,mdl,fl,index,NumNonLin,fn,fv):

    Grp=1
    text = '\n /* Elements of VMS' + a['@index']
    text += '*/\n\n'
    if 'Group' in a.keys(): Grp = 2

    if not hasattr(VMSStamp, "counter"):
        VMSStamp.counter = 0
    
    P = a['G'][0]['#text']
    N = a['G'][1]['#text']

# avoiding rewrite, in case of multiple Memristor
    if VMSStamp.counter==0:
        text += '\tdouble Un_VM, Uo_VM, Omega_M, Omegaold_M, Omegaxold_M, Phi_M, PhiOld_M;\n'
        text += '\tdouble Geq_VM, Ieq_VM, Sr_VM, Sr_VMO, GGeq_M, IIeq_M;\n'
        text += '\tdouble xp_VM, gq_VM, Khv_VM, Kpv_VM, Kv_VM, Jw, Jv, Fv;\n'
        text += '\tstatic int tt_VM = 0;\n\n'
    
    ir = a['Group']
    fn.write(str(ir)+'\t'+P+'\t'+N+'\t'+mdl[a['M']]['@Phi0']+'\n')

    text += '\tUn_VM = 0.;\n\tUo_VM = 0.;\n'
    if int(N)>0: text += '\tUn_VM += -Vx['+N+'];\n'
    if int(P)>0: text += '\tUn_VM += Vx['+P+'];\n'


    if int(N)>0: text += '\tUo_VM += -uxtold['+N+'];\n'
    if int(P)>0: text += '\tUo_VM += uxtold['+P+'];\n'

#    text +='\tPhiOld_M = uxtold['+str(ir)+'];\n'
#    text +='\tPhi_M = Vx['+str(ir)+'];\n'
    text +='\tOmega_M = 0.;\n\tOmegaxold_M = 0.;\n\tOmegaold_M = 0.;\n\tPhi_M = 0;\n\n'

#    if int(N)>0: text += '\tOmegaxold_M += -uxtold['+N+'];\n'
#    if int(P)>0: text += '\tOmegaxold_M += uxtold['+P+'];\n'
    text +='\tOmegaxold_M = uxtold['+str(ir)+'];\n'
#    if int(N)>0: text += '\tOmegaold_M += -Vx['+N+'];\n'
#    if int(P)>0: text += '\tOmegaold_M += Vx['+P+'];\n'
    text +='\tOmegaold_M = Vx['+str(ir)+'];\n\n\n'

    comp = {}
    for v ,t in mdl[a['M']].items():
        comp[v.replace("@","").lower()]=t

    text +='\tJw = ((1/'+comp['hh']+'));\n'
    text +='\tJv = '+comp['eta']+'*'+comp['lambda']+'*1.e-3*cosh('+comp['eta']+'*Uo_VM);\n'
    text +='\tFv = (1/Jw)*(Omegaxold_M/'+comp['hh']+')-('+comp['lambda']+'*1.e-3*sinh('+comp['eta']+'*Uo_VM));\n'
    text +='\tPhi_M = (1/Jw)*(Omegaold_M/'+comp['hh']+')-('+comp['lambda']+'*1.e-3*sinh('+comp['eta']+'*Un_VM));\n'
    text +='\tGGeq_M = (1/Jw)*Jv;\n\tIIeq_M = Fv-(1/Jw)*(Jv*Uo_VM);\n'
    text +='\tPhi_M =  IIeq_M-(GGeq_M*Un_VM);\n\n'
    text +='\tSr_VMO = ((Phi_M - IIeq_M)/GGeq_M)+Un_VM;\n\n'
#    text +='\tSr_VMO = Fv;\n\n'

    text +='\tPhiOld_M = Fv;\n'
    text +='\tKhv_VM = Phi_M*'+comp['gamma']+'*sinh('+comp['delta']+'*Un_VM)+(1-Phi_M)*'+comp['alpha']+'*(1-exp(-'+comp['beta']+'*Un_VM));\n'
    text +='\tKv_VM = PhiOld_M*'+comp['gamma']+'*sinh('+comp['delta']+'*Uo_VM)+(1-PhiOld_M)*'+comp['alpha']+'*(1-exp(-'+comp['beta']+'*Uo_VM));\n'
    text +='\tKpv_VM = (1-PhiOld_M)*'+comp['alpha']+'*'+comp['beta']+'*exp(-'+comp['beta']+'*Uo_VM)+(PhiOld_M*'+comp['gamma']+'*'+comp['delta']+'*cosh('+comp['delta']+'*Uo_VM));\n'
    text +='\tIeq_VM = Kv_VM + (Kpv_VM * Uo_VM);\n'
    text +='\tGeq_VM = Kpv_VM;\n'
    text +='\tSr_VM = Kv_VM;\n\n'
#    text +='\tSr_VM = Kv_VM;\n\n'




    if int(P) >0:
        text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - GGeq_M;\n'
        ind.add_ind(index,str(ir),P)
        text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_VM;\n'
        ind.add_ind(index,P,P)
        text +='\trval['+P+'] += -Ieq_VM;\n'
#        text +='\tfvec['+P+'] += Vx['+P+'];\n'
        text +='\tfvec['+P+'] += Sr_VM;\n'
    if int(P)>0 and int(N)>0:
        text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq_VM;\n'
        ind.add_ind(index,P,N)
        text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq_VM;\n'
        ind.add_ind(index,N,P)
    if int(N) >0:
        text +='\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] + GGeq_M;\n'
        ind.add_ind(index,str(ir),N)
        text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq_VM;\n'
        ind.add_ind(index,N,N)
        text +='\trval['+N+'] += Ieq_VM;\n'
#        text +='\tfvec['+N+'] += -Vx['+N+'];\n'
        text +='\tfvec['+N+'] += -Sr_VM;\n'

    text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
    ind.add_ind(index,str(ir),str(ir))
    text +='\trval['+str(ir)+'] += IIeq_M;\n'
    text +='\tfvec['+str(ir)+'] += Sr_VMO;\n'

    fl.write(text)
    VMSStamp.counter=1
