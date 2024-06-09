/*
	Member atimes of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 void LinSolver::atimes(double *x, double *r, int itrnsp){

	if(itrnsp){
		 sprstx(x,r);
  	}else{
		 sprsax(x,r);
	}

 }

