/*
	Member asolve of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 void LinSolver::asolve(double *b, double *x, int itrnsp){
  int i = 1;

  for(int k=1; k<=size; k++){

	if(mna[k][k] != 0){
		x[i] = b[i]/mna[k][k];
	}else{
		x[i] = b[i];
	} 

  }
/*
  for(int k = 1; k <= len; k++){

    if(row[k]==col[k]){
      	if(val[k]==0.0){
		x[i] = b[i]; i++;// cout<<"singular diagonal metrix in asolve, program exited '\n";}
	}else{
		x[i] = b[i]/val[k]; i++;
    	}
    }

 }
*/

}
