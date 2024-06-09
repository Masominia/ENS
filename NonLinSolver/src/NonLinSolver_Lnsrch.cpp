/*
	Member Lnsrch of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee, based on
	routine newt of Numerical Recipes book
	
*/


#include "nonlinsolver.h"

static double sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg*sqrarg)

static double maxarg1,maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ? (maxarg1) : (maxarg2))

 bool NonLinSolver::lnsrch(double xold[], double fold, double g[], double np[], double x[], double* f, double stpmax){

	int i;
	double a,alam,alam2,alamin,b,disc,f2,rhs1,rhs2,slope,sum,temp,
		test,tmplam;

	check=false;
	for (sum=0.0,i=1;i<=nlnp;i++) sum += np[i]*np[i];
	sum=sqrt(sum);
	if (sum > stpmax)
		for (i=1;i<=nlnp;i++) np[i] *= stpmax/sum;
	for (slope=0.0,i=1;i<=nlnp;i++)
		slope += g[i]*np[i];
	if (slope >= 0.0){/* cout<< "Roundoff problem in lnsrch.\n";*/}
	test=0.0;
	for (i=1;i<=nlnp;i++) {
		temp=fabs(np[i])/FMAX(fabs(xold[i]),1.0);
		if (temp > test) test=temp;
	}
	alamin=TOLX/test;
	alam=1.0;
	for (;;) {
		for (i=1;i<=nlnp;i++) x[i]=xold[i]+alam*np[i];
		*f=fmin(x);
		if (alam < alamin) {
			for (i=1;i<=nlnp;i++) x[i]=xold[i];
			check=true;
			return check;
		} else if (*f <= fold+ALF*alam*slope) return check;
		else {
			if (alam == 1.0)
				tmplam = -slope/(2.0*(*f-fold-slope));
			else {
				rhs1 = *f-fold-alam*slope;
				rhs2=f2-fold-alam2*slope;
				a=(rhs1/(alam*alam)-rhs2/(alam2*alam2))/(alam-alam2);
				b=(-alam2*rhs1/(alam*alam)+alam*rhs2/(alam2*alam2))/(alam-alam2);
				if (a == 0.0) tmplam = -slope/(2.0*b);
				else {
					disc=b*b-3.0*a*slope;
					if (disc < 0.0) tmplam=0.5*alam;
					else if (b <= 0.0) tmplam=(-b+sqrt(disc))/(3.0*a);
					else tmplam=-slope/(b+sqrt(disc));
				}
				if (tmplam > 0.5*alam)
					tmplam=0.5*alam;
			}
		}
		alam2=alam;
		f2 = *f;
		alam=FMAX(tmplam,0.1*alam);
	}


 }

