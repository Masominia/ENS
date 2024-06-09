import math as mt

def link_active(c,tr):

	Qz_M=0.1 
	alpha=1.1 
	beta=2e-1
	Qn_M = c

	xp_M = mt.exp(-alpha*(Qn_M-Qz_M))
	gq_M = 1./(1.+beta*xp_M)



	te = False
	if gq_M>tr: te = True
	return te
