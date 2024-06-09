/*
	Member fdjac of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "nonlinsolver.h"



 void  NonLinSolver::fdjac (double x[]){

  double idt;

	ResetW();

	NonLinStamp(x);
	SourceStamp();

	if(Delt>0.){
		idt = 1./Delt;
	}else{
		idt = 0.;
	}
/*
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + lmna[i]; rval[i] += lrval[i];}
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + dmna[i]; rval[i] += drval[i];}
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + nmna[i]; rval[i] += nrval[i];}
*/
	for(int i=1; i<=size; i++){
//		mna[i] = mna[i] + lmna[i];
		ssum(mna[i],lmna[i],dmna[i],idt);
		ssum(mna[i],nmna[i],ndmna[i],1.);
		mna[i] = mna[i] + smna[i];
	}

	for(int i=1; i<=size; i++) {rval[i] += lrval[i]+nrval[i]+ndrval[i]+srval[i];}
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			rval[i] += *(dmna[i][j])*uxtold[j];
		}
	}



 }

