/*
	Member linbcg of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 void LinSolver::linbcg(double *x, int itol, double tol, int itmax, int *iter, double *err){
	int j;
	double ak,akden,bk,bkden,bknum,bnrm,dxnrm,xnrm,zm1nrm,znrm;

        for(int i =1; i<=np; i++){
	 p[i] = 0.0;
         pp[i] = 0.0;
         r[i] = 0.0;
         rr[i] = 0.0;
         z[i] = 0.0;
         zz[i] = 0.0;
        }

	*iter=0;

	atimes(x,r,0);

	for (j=1;j<=np;j++) {
		r[j]=rval[j]-r[j];
		rr[j]=r[j];

	}

	if (itol == 1) {
		bnrm=snrm(rval,itol);
		asolve(r,z,0);
	}
	else if (itol == 2) {
		asolve(rval,z,0);
		bnrm=snrm(z,itol);
		asolve(r,z,0);
	}
	else if (itol == 3 || itol == 4) {
		asolve(rval,z,0);
		bnrm=snrm(z,itol);
		asolve(r,z,0);
		znrm=snrm(z,itol);
	} else {cout<<"illegal itol in linbcg\n";}

	while (*iter <= itmax) {
		++(*iter);

		asolve(rr,zz,1);

		for (bknum=0.0,j=1;j<=np;j++) bknum += z[j]*rr[j];

		if (*iter == 1) {
			for (j=1;j<=np;j++) {
				p[j]=z[j];
				pp[j]=zz[j];
			}
		}

		else {
			bk=bknum/bkden;
			for (j=1;j<=np;j++) {
				p[j]=bk*p[j]+z[j];
				pp[j]=bk*pp[j]+zz[j];
			}
		}

		bkden=bknum;
		atimes(p,z,0);

		for (akden=0.0,j=1;j<=np;j++) akden += z[j]*pp[j];

		ak=bknum/akden;
		atimes(pp,zz,1);

		for (j=1;j<=np;j++) {
			x[j] += ak*p[j];
			r[j] -= ak*z[j];
			rr[j] -= ak*zz[j];
		}

		asolve(r,z,0);

		if (itol == 1)
			*err=snrm(r,itol)/bnrm;
 		else if (itol == 2)
			*err=snrm(z,itol)/bnrm;
		else if (itol == 3 || itol == 4) {
			zm1nrm=znrm;
			znrm=snrm(z,itol);
			if (fabs(zm1nrm-znrm) > EPS*znrm) {
				dxnrm=fabs(ak)*snrm(p,itol);
				*err=znrm/fabs(zm1nrm-znrm)*dxnrm;
			} else {
				*err=znrm/bnrm;
				continue;
			}
			xnrm=snrm(x,itol);
			if (*err <= 0.5*xnrm) *err /= xnrm;
			else {
				*err=znrm/bnrm;
				continue;
			}
		}

		//		printf("iter=%4d err=%12.6f\n",*iter,*err);
	if (*err <= tol) break;
	}





}
