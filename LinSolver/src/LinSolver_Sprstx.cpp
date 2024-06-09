/*
	Member sprstx of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 void LinSolver::sprstx(double *x, double *b){
	for(int i = 1; i <= np ; i++)b[i] = 0.0;

	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; i++){
			b[i] += mna[j][i]*x[j]; 
		
		}
	}

   }
