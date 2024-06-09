/*
	Member snrm of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 double LinSolver::snrm(double *sx, int itol){

  int i,isamax;
  double ans;
  	if(itol<=3){
    		ans = 0.0;
    		for(i=1; i<=np; i++) ans+=sx[i]*sx[i];
    		return sqrt(ans);
  	}else{
    		isamax = 1;
    		for (i=1; i<=np; i++){
      			if(fabs(sx[i])> fabs(sx[isamax])) isamax = i;
    		}
    		return fabs(sx[isamax]);
  	}

}
