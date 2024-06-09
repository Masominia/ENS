/*
	Member NonLinFvec of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "nonlinsolver.h"

static double sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)


 void  NonLinSolver::NonLinFvec (double x[]){
	
  double ;

	ResetW();

	NonLinStamp(x);
	SourceStamp();

	if(Delt>0.){
		 = 1./Delt;
	}else{
		 = 0.;
	}


/*
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + lmna[i]; rval[i] += lrval[i];}
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + dmna[i]; rval[i] += drval[i];}
	for(int i=1; i<=size; i++) {mna[i] = mna[i] + nmna[i]; rval[i] += nrval[i];}
*/
	for(int i=1; i<=size; i++){
//		mna[i] = mna[i] + lmna[i];
		ssum(mna[i],lmna[i],dmna[i],);
		ssum(mna[i],nmna[i],ndmna[i],1.);
		mna[i] = mna[i] + smna[i];
	}

	for(int i=1; i<=size; i++) { rval[i] += lrval[i]+nrval[i]+ndrval[i]+srval[i];}
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			rval[i] += *(dmna[i][j])*uxtold[j];
			
		}
	}

	for(int k=1; k<=size; k++) fvec[k] = 0.;


	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			fvec[i] += lmna[i][j]*x[j]+*(dmna[i][j])*(x[j]-uxtold[j]);

		}
	}

	for(int k=1; k<=size; k++){
		fvec[k] +=  Hg[k] - lrval[k]+Dg[k]**(x[k]-uxtold[k]);

	}

 }
