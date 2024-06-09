from Stamp import ind
from Stamp import CCMemristorStamp
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
        text += '\tdouble Un_VM, Uo_VM, Omega_M, Omegaold_M, Omegaxold_M;\n'
        text += '\tdouble Geq_VM, Ieq_VM, Sr_VM, GGeq_M, IIeq_M;\n'
        text += '\tdouble xp_VM, gq_VM, Kh_VM, Kp_VM, Kv_VM, Jw, Jv, Fwv;\n'
        text += '\tstatic int tt_VM = 0;\n\n'
    
    ir = a['Group']
    fn.write(str(ir)+'\t'+P+'\t'+N+'\t'+mdl[a['M']]['@Phi0']+'\n')

    text += '\tUn_VM = 0.;\n\tUo_VM = 0.;\n'
    if int(N)>0: text += '\tUn_VM += -Vx['+N+'];\n'
    if int(P)>0: text += '\tUn_VM += Vx['+P+'];\n'


    if int(N)>0: text += '\tUo_VM += -uxtold['+N+'];\n'
    if int(P)>0: text += '\tUo_VM += uxtold['+P+'];\n\n\n'

#    text +='\tPhiOld_M = uxtold['+str(ir)+'];\n'
#    text +='\tPhi_M = Vx['+str(ir)+'];\n'
#    text +='\tOmega_M = 0.;\n\tOmegaxold_M = 0.;\n\tOmegaold_M = 0.;\n\n'

    text +='\tOmegaxold_M = uxtold['+str(ir)+'];\n'
    text +='\tOmega_M = Vx['+str(ir)+'];\n\n'

    comp = {}
    for v ,t in mdl[a['M']].items():
        comp[v.replace("@","").lower()]=t

#    text +='\tJw = '+comp['hh']+';\n'
    text +='\tJw = ('+comp['hh']+'*'+comp['tau']+')/('+comp['hh']+'+'+comp['tau']+');\n'
    text +='\tJv = -'+comp['eta']+'*'+comp['lambda']+'*cosh('+comp['eta']+'*Un_VM);\n'
#    text +='\tOmega_M = ((('+comp['hh']+'*'+comp['tau']+')/('+comp['hh']+'+'+comp['tau']+'))*Omegaxold_M/'+comp['hh']+')+(('+comp['hh']+'*'+comp['tau']+')/('+comp['hh']+'+'+comp['tau']+'))*'+comp['lambda']+'*sinh('+comp['eta']+'*Un_VM);\n'
    text +='\tFwv = -Jv*(Un_VM-Uo_VM)-(1/Jw)*(Omega_M-Omegaxold_M);\n'
    text +='\tGGeq_M = Jw*Jv;\n\tIIeq_M = Omegaxold_M + Jw*Jv*Un_VM - Jw*Fwv;\n\n'
#    text +='\tOmega_M = 0.;\n'
#    text +='\tGeq_VM = 0.;\n\n'
    text +='\tKv_VM = Omega_M*'+comp['gamma']+'*'+comp['delta']+'*cosh('+comp['delta']+'*Un_VM)-(1-Omega_M)*'+comp['alpha']+'*'+comp['beta']+'*exp(-'+comp['beta']+'*Un_VM);\n'
    text +='\tIeq_VM = (1-Omegaxold_M)*'+comp['alpha']+'*(1-exp(-'+comp['beta']+'*Uo_VM))+Omegaxold_M*'+comp['gamma']+'*sinh('+comp['delta']+'*Uo_VM)-Kv_VM*Uo_VM;\n'
    text +='\tGeq_VM = Kv_VM*Un_VM;\n\n'
#    text +='\tIeq_VM = 0.;\n\n'
#    text +='\tOmegaxold_M = Omega_M;\n'
#    text +='\tOmegaxold_M =1e6;\n\n\n'

    if int(P) >0:
        text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - GGeq_M;\n'
        ind.add_ind(index,str(ir),P)
        text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_VM;\n'
        ind.add_ind(index,P,P)
        text +='\trval['+P+'] += -Ieq_VM;\n'
        text +='\tfvec['+P+'] += Vx['+P+'];\n'
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
        text +='\tfvec['+N+'] += -Vx['+N+'];\n'

    text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
    ind.add_ind(index,str(ir),str(ir))
    text +='\trval['+str(ir)+'] += IIeq_M;\n'
    text +='\tfvec['+str(ir)+'] += Omega_M;\n'

    fl.write(text)
    VMSStamp.counter=1
