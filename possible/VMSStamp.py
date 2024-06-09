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
        text += '\tdouble Un_M, Uo_M, Omega_M, Omegaold_M, Omegaxold_M;\n'
        text += '\tdouble Geq_M, Ieq_M, Sr_M, GGeq_M, IIeq_M;\n'
        text += '\tdouble xp_M, gq_M, Kh_M, Kp_M, Jw, Jv, Fwv;\n'
        text += '\tdouble alpha, beta, gamma, delta;\n'
        text += '\tdouble aalpha, Gf, Gn;\n'
        text += '\tdouble H, tau, landa, eta;\n'
        text += '\tstatic int tt_M = 0;\n\n'
    
    ir = a['Group']
    fn.write(str(ir)+'\t'+P+'\t'+N+'\t'+mdl[a['M']]['@Phi0']+'\n')

    text += '\tUn_M = 0.;\n\tUo_M = 0.;\n'
    if int(N)>0: text += '\tUn_M += -Vx['+N+'];\n'
    if int(P)>0: text += '\tUn_M += Vx['+P+'];\n'


    if int(N)>0: text += '\tUo_M += -uxtold['+N+'];\n'
    if int(P)>0: text += '\tUo_M += uxtold['+P+'];\n'

#    text +='\tPhiOld_M = uxtold['+str(ir)+'];\n'
#    text +='\tPhi_M = Vx['+str(ir)+'];\n'
#    text +='\tOmega_M = 0.;\n\tOmegaxold_M = 0.;\n\tOmegaold_M = 0.;\n\n'

    func_text = mdl[a['M']]['#text']
    args = mdl[a['M']]

    for k in args.keys():
        if k != '@name' and k != '#text':	
            func_text = func_text.replace(k.replace("@",""),args[k])

    text +='\n\t'+func_text+'\n\n'
    text +='\tJw = (H*tau)/(H+tau);\n\tJv = -eta*landa*cosh(eta*Un_M);\n\n'
    text +='\tFwv = -Jv*(Un_M-Uo_M)-(1/Jw)*(Omega_M-Omegaxold_M);\n'
    text +='\tGGeq_M = Jw*Jv;\n\tIIeq_M = Omegaxold_M + Jw*Jv*Omegaxold_M - Jw*Fwv;\n\n'
    text +='\tOmega_M = -(GGeq_M*Un_M)+IIeq_M;\n'
    text +='\tGeq_M = 1/((10.*Omega_M*1e7)+(100000*(1-Omega_M*1e7)));\n\n'
    text +='\tIeq_M = (1-Omega_M)*alpha*(1-exp(-beta*Un_M))+Omega_M*gamma*sinh(delta*Un_M);\n\n'
    text +='\tOmegaxold_M = Omegaold_M;\n'
    text +='\tOmegaold_M = Omega_M;\n\n'

    if int(P) >0:
        text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - GGeq_M;\n'
        ind.add_ind(index,str(ir),P)
        text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_M;\n'
        ind.add_ind(index,P,P)
        text +='\trval['+P+'] += -Ieq_M;\n'
        text +='\tfvec['+P+'] += Vx['+P+'];\n'
    if int(P)>0 and int(N)>0:
        text +='\tmna['+P+']('+N+') = mna['+P+']['+N+'] - Geq_M;\n'
        ind.add_ind(index,P,N)
        text +='\tmna['+N+']('+P+') = mna['+N+']['+P+'] - Geq_M;\n'
        ind.add_ind(index,N,P)
    if int(N) >0:
        text +='\tmna['+str(ir)+']('+N+') = mna['+str(ir)+']['+N+'] + GGeq_M;\n'
        ind.add_ind(index,str(ir),N)
        text +='\tmna['+N+']('+N+') = mna['+N+']['+N+'] + Geq_M;\n'
        ind.add_ind(index,N,N)
        text +='\trval['+N+'] += Ieq_M;\n'
        text +='\tfvec['+N+'] += -Vx['+N+'];\n'

    text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
    ind.add_ind(index,str(ir),str(ir))
    text +='\trval['+str(ir)+'] += IIeq_M;\n'
    text +='\tfvec['+str(ir)+'] += Omega_M;\n'

    fl.write(text)
    VMSStamp.counter=1
