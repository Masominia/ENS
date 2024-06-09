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
        text += '\tdouble Un_CM, Uo_CM, Omegaold_CM, Omegaxold_CM, Omega_CM, Qold_M;\n'
        text += '\tdouble Geq_CM, Ieq_CM, Sr_CM, Sr_CMO, GGeq_CM, IIeq_CM, QGeq_CM, QIeq_CM;\n'
        text += '\tdouble Xp_CM, X_CM, Khq_CM, Kpq_CM, Kq_CM, Ko_CM, Fwv, Jw, Rold, Rxold, Ton, dr, K_CM;\n'
        text += '\tstatic int tt_VM = 0;\n\n'
    
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

    comp = {}
    for v ,t in mdl[a['M']].items():
        comp[v.replace("@","").lower()]=t

    text +='\tTon = '+comp['uv']+'*('+comp['ron']+'/'+comp['d']+');\n'
    text +='\tRold = ('+comp['ron']+'*(Omegaold_CM/'+comp['d']+'))+('+comp['roff']+'*(1-(Omegaold_CM/'+comp['d']+')));\n'
    text +='\tRxold = ('+comp['ron']+'*(Omegaxold_CM/'+comp['d']+'))+('+comp['roff']+'*(1-(Omegaxold_CM/'+comp['d']+')));\n'
    text +='\tdr = ('+comp['ron']+' - '+comp['roff']+')/'+comp['d']+';\n'
    text +='\tK_CM = (('+comp['hh']+'*'+comp['uv']+'*('+comp['ron']+'/'+comp['d']+'))/(Rold));\n'
    text +='\tKo_CM = (('+comp['hh']+'*'+comp['uv']+'*('+comp['ron']+'/'+comp['d']+'))/(Rxold));\n'
    text +='\tFwv = Omegaold_CM - Omegaxold_CM - (K_CM * Un_CM);\n'
    text +='\tJw = 1 + ((K_CM/Rold) * dr * Un_CM);\n'
    text +='\tQold_M = - Omegaxold_CM - (Ko_CM * Uo_CM);\n'
    text +='\tGGeq_CM = K_CM/Jw;\n\tIIeq_CM = (Fwv - (Jw * Omegaold_CM) + (K_CM * Un_CM))/(-1 * Jw);\n'
    text +='\tOmega_CM =  IIeq_CM+(GGeq_CM*Un_CM);\n\n'

    text +='\tSr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;\n\n'

    text +='\tX_CM = Rold * ((Omegaold_CM - Omegaxold_CM)/'+comp['hh']+');\n'    
    text +='\tXp_CM = (1/'+comp['hh']+') * Rold;\n'
#    text +='\tIeq_CM = (IIeq_CM - Omegaold_CM)/('+comp['hh']+')*(1/Ton);\n'
#    text +='\tGeq_CM = GGeq_CM/('+comp['hh']+')*(1/Ton);\n'
#    text +='\tSr_CM = -1 * GGeq_CM * Un_CM +(Q_M - IIeq_CM);\n\n'
#    text +='\tIeq_CM = (IIeq_CM - Omegaxold_CM)*(1/'+comp['hh']+')*('+comp['d']+'/('+comp['uv']+'*'+comp['ron']+'));\n'
#    text +='\tGeq_CM = GGeq_CM*(1/'+comp['hh']+')*('+comp['d']+'/('+comp['uv']+'*'+comp['ron']+'));\n'
#    text +='\tIeq_CM = ((-1 * dr)/(Rold*Rold)*Un_CM*(Omega_CM - Omegaold_CM));\n'
    text +='\tGeq_CM = 1/Rold;\n'
    text +='\tIeq_CM = 0.;\n'
    text +='\tSr_CM = Ieq_CM + Geq_CM*Un_CM;\n\n'




    if int(P) >0:
        text +='\tmna['+str(ir)+']('+P+') = mna['+str(ir)+']['+P+'] - GGeq_CM;\n'
        ind.add_ind(index,str(ir),P)
        text +='\tmna['+P+']('+P+') = mna['+P+']['+P+'] + Geq_CM;\n'
        ind.add_ind(index,P,P)
        text +='\trval['+P+'] += -Ieq_CM;\n'
#        text +='\tfvec['+P+'] += Vx['+P+'];\n'
        text +='\tfvec['+P+'] += Sr_CM;\n'
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
#        text +='\tfvec['+N+'] += -Vx['+N+'];\n'
        text +='\tfvec['+N+'] += -Sr_CM;\n'

    text +='\tmna['+str(ir)+']('+str(ir)+') = mna['+str(ir)+']['+str(ir)+'] + 1.;\n'
    ind.add_ind(index,str(ir),str(ir))
    text +='\trval['+str(ir)+'] += IIeq_CM;\n'
    text +='\tfvec['+str(ir)+'] += Sr_CMO;\n'

    fl.write(text)
    CMSStamp.counter=1
