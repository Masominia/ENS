/*
	Class member DC_Analyse  of the class linsolver
	written by Ehsan Nedaaee Oskoee
	
*/


#include "linsolver.h"

 bool LinSolver::Met_bicgstab(double *X){

	bool stat = false;
        int iter = 0;
        double tol = 1.e-9;


//	for(int i=1; i<=nx; i++)  X[i] = 0.;

	iter = bicgstab(X,tol,false);


	
	stat = true;
	return stat;
 }

