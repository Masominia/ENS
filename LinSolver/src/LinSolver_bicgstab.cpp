/*
	Member bicgstab of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	In written process, I've used the method developed in 
	Mathematisches Institut Albert-Ludwigs-Universität Freiburg
	web:http://aam.mathematik.uni-freiburg.de/IAM/Research/projectskr/lin_solver/
	
*/


#include "linsolver.h"


 int LinSolver::bicgstab( double *x, double eps, bool detailed ) {

  unsigned int N = np;

			
  double *s   = h;
  double rTh, rTAd, rTr, alpha, beta, omega, st, tt;
  int its=0;
  double err=eps*eps*ddot(N,rval,1,rval,1);
  // f"ur's Abbruchkriterium (*)  -- r enth"alt immer das Residuum r=Ax-b
//  double *r = new double[N];

  sprsax(x,r);
  daxpy(N,-1.,rval,1,r,1);
  dcopy(N,r,1,pp,1);
  dcopy(N,pp,1,h,1);
  dcopy(N,h,1,p,1);
  assert( ddot(N,p,1,p,1)>1e-40 );
  rTh=ddot(N,p,1,h,1);
  rTr=ddot(N,r,1,r,1);
  while ( rTr>err ) {
    sprsax(pp,z);
    rTAd=ddot(N,p,1,z,1);
//cout<<"in bicgstab, rTAd = "<<rTAd<<" and rTh = "<<rTh<<endl;
//for(int i=1; i<=N; i++)
//	cout<<pp[i]<<"  "<<p[i]<<"  "<<z[i]<<endl;
	
    assert( fabs(rTAd)>1e-40 );
    alpha=rTh/rTAd;
    daxpy(N,-alpha,z,1,r,1);
    dcopy(N,h,1,s,1);
    daxpy(N,-alpha,z,1,s,1);
    sprsax(s,zz);
    daxpy(N,1.,zz,1,rr,1);
    dscal(N,alpha,rr,1);
    st=ddot(N,s,1,zz,1);
    tt=ddot(N,zz,1,zz,1);
    if ( fabs(st)<1e-40 || fabs(tt)<1e-40 )
      omega = 0.;
    else
      omega = st/tt;
    daxpy(N,-omega,zz,1,r,1);
    daxpy(N,-alpha,pp,1,x,1);
    daxpy(N,-omega,s,1,x,1);
    dcopy(N,s,1,h,1);
    daxpy(N,-omega,zz,1,h,1);
    beta=(alpha/omega)/rTh; rTh=ddot(N,p,1,h,1); beta*=rTh;
    dscal(N,beta,pp,1);
    daxpy(N,1.,h,1,pp,1);
    daxpy(N,-beta*omega,z,1,pp,1);
    rTr=ddot(N,r,1,r,1);
    if ( detailed )
      cout<<"bicgstab "<<its<<"\t"<<sqrt(rTr)<<endl;
    ++its;
  }
  return its;
}


	
