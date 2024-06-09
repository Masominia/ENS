/*
	Member fmin of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "nonlinsolver.h"

static double sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)


 double NonLinSolver::fmin (double x[]){
	int i;
	double sum;

	NonLinFvec(x);

	for (sum=0.0,i=1;i<=nlnp;i++) sum += SQR(fvec[i]);
	return 0.5*sum;



 }

