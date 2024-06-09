/*
	Member mnewt of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee, based on
	routine newt of Numerical Recipes book
	
*/


#include "nonlinsolver.h"

 bool NonLinSolver::mnewt(double x[]){

	int k,i;
	double errx,errf,d;
	bool stat = true;

        for(int i =1; i<= nlnp; i++){
        	nlxold[i]=0.0;
	}

	for (k=1;k<=MAXITS;k++) {
		fdjac(x);
		d = fmin(x);
		errf=0.0;
		for (i=1;i<=nlnp;i++) errf += fabs(fvec[i]);
		if (errf <= TOLF) return stat;
		for (i=1;i<=nlnp;i++) nlxold[i] = x[i];
		if(!LinSetSol(x)) cout<<"error in solving linear set of equations\n";
		Do_Step_Limit(x,nlxold);
		errx=0.0;
		for (i=1;i<=nlnp;i++) {
			errx += fabs(x[i]-nlxold[i]);
		}
		if (errx <= TOLX) return stat;
	}
	stat = false;
	return stat;
}
