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
        text += '\tdouble Geq_CM, Ieq_CM, Sr_CM, Sr_CMO, GGeq_CM, IIeq_CM;\n'
        text += '\tdouble dH_W, Rch_W, Gth_W, Jw, Jv, Fwv, ddH_I, ddH_II, ddH_III, dRch, dGth, Rch_I, Rch_II, dH_I, dH_II, dH_III;\n'
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


    text +='\tRch_I = (('+comp['ins']+' * '+comp['l']+')/(M_PI * ('+comp['rch']+' * '+comp['rch']+')));\n'
    text +='\tRch_II = 1.+((('+comp['ins']+' / '+comp['met']+')-1.) * (Omegaold_CM * Omegaold_CM));\n'
    text +='\tRch_W = Rch_I / Rch_II;\n'
    text +='\tdRch = 2. * ((('+comp['ins']+'/'+comp['met']+')-1.)*M_PI*('+comp['rch']+'*'+comp['rch']+')*(Un_CM * Un_CM)*Omegaold_CM)/('+comp['ins']+' * '+comp['l']+');\n\n'

    text +='\tGth_W = 2.*M_PI*'+comp['l']+'*'+comp['kap']+'/log(1./Omegaold_CM);\n'
    text +='\tdGth = -2.*M_PI*'+comp['l']+'*'+comp['kap']+'*'+comp['tem']+'/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));\n\n'

    text +='\tdH_I = M_PI*'+comp['l']+'*'+comp['rch']+'*'+comp['rch']+';\n'
    text +='\tdH_II = '+comp['cp']+'*'+comp['tem']+'*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));\n'
    text +='\tdH_III = 2. * '+comp['dh']+' * Omegaold_CM;\n'
    text +='\tdH_W = dH_I * (dH_II + dH_III);\n'
    text +='\tddH_I = 2. *'+comp['cp']+' * '+comp['tem']+' / log(Omegaold_CM);\n'
    text +='\tddH_II = -1.*'+comp['cp']+'*'+comp['tem']+'*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));\n'
    text +='\tddH_III = -1.*'+comp['cp']+'*'+comp['tem']+'*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));\n\n'

    text +='\tFwv =((Omegaold_CM-Omegaxold_CM)/'+comp['hh']+')-1.e-4*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*'+comp['tem']+'))/dH_W);\n'
    text +='\tJw = (1/'+comp['hh']+')+1.e-4*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*'+comp['tem']+'))*((2.*'+comp['dh']+')+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-1.e-4*((dRch+dGth)/dH_W);\n'
    text +='\tJv = (-2.*Un_CM)/(dH_W*Rch_W);\n\n'

    text +='\tIIeq_CM = (Omegaold_CM + (Fwv/(-1.*Jw)) + ((Jv/Jw)*Un_CM));\n'
    text +='\tGGeq_CM = Jv/(-1.*Jw);\n'  
    text +='\tOmega_CM = IIeq_CM+(GGeq_CM*Un_CM);\n'
    text +='\tSr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;\n\n'


    text +='\tGeq_CM = 1./Rch_W;\n'
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
