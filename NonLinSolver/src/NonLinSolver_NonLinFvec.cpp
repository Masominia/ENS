/*
	Member NonLinFvec of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "nonlinsolver.h"
static double sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)


 void  NonLinSolver::NonLinFvec (double x[]){
	
	Make(x);
 }
