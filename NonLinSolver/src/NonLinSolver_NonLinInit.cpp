/*
	Member Init of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "nonlinsolver.h"

 void NonLinSolver::NonLinInit(int a)
 {

	
	nlg 	+= 1;
	nlxold 	+= 1;
	nlbx 	+= 1;



	delete [] nlg;
	delete [] nlxold;
	delete [] nlbx;



	nlnp = a;
	
	nlg 	= new double [nlnp];
	nlxold	= new double [nlnp];
	nlbx 	= new double [nlnp];



	nlg 	-= 1;
	nlxold 	-= 1;
	nlbx 	-= 1;



 }
