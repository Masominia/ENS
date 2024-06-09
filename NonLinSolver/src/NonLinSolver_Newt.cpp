/*
	Member newt of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee, based on
	routine newt of Numerical Recipes book
	
*/


#include "nonlinsolver.h"

static double sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)

static double maxarg1,maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ? (maxarg1) : (maxarg2))

 bool NonLinSolver::newt(double x[]){

	check = false;
	int i,its,j;
	double den,f,fold,stpmax,sum,temp,test;

        for(int i =1; i<= nlnp; i++){
	 nlg[i]=0.0;
         nlxold[i]=0.0;
         nlbx[i]=0.0;
	}


	f=fmin(x);

	test=0.0;

	for (i=1;i<=nlnp;i++)
		if (fabs(fvec[i]) > test) test=fabs(fvec[i]);

	if (test < 0.01*TOLF) {
		check=false;
		return check;
	}

	for (sum=0.0,i=1;i<=nlnp;i++) sum += SQR(x[i]);

	stpmax=STPMX*FMAX(sqrt(sum),(double)nlnp);

	for (its=1;its<=MAXITS;its++) {

	  fdjac(x);                

		sprsax(fvec, nlg); // has been changed. inplace of above for

		for (i=1;i<=nlnp;i++) nlxold[i]=x[i];
		fold=f;


		if(!LinSetSol(x)) cout<<"error in solving linear set of equations\n";

		Do_Step_Limit(x,nlxold);

		for(i=1; i<=nlnp; i++) nlbx[i] = x[i] - nlxold[i]; 	//after solving ax= b, ux is x^{k+1}, therefore, 

		if(!lnsrch(nlxold,fold,nlg,nlbx,x,&f,stpmax)) ;//cout<<"error in finding new direction in lnsrch\n";

		f=fmin(x);

		test=0.0;
		for (i=1;i<=nlnp;i++)
			if (fabs(fvec[i]) > test) test=fabs(fvec[i]);
		if (test < TOLF) {
			check=false;
			return check;
		}
		if (check) {
			test=0.0;
			den=FMAX(f,0.5*nlnp);
			for (i=1;i<=nlnp;i++) {
				temp=fabs(nlg[i])*FMAX(fabs(x[i]),1.0)/den;
				if (temp > test) test=temp;
			}
			check=(test < TOLMIN);
			return check;
		}
		test=0.0;
		for (i=1;i<=nlnp;i++) {
			temp=(fabs(x[i]-nlxold[i]))/FMAX(fabs(x[i]),1.0);
			if (temp > test) test=temp;
		}
		if (test < TOLX) return check;
	}

	cout<<"MAXITS exceeded in newt\n";
	return check;
 }
	
