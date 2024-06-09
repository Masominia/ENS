/*
	Class member Lin_Solver  of the class linsolver
	written by Ehsan Nedaaee Oskoee
	
*/


#include "linsolver.h"

 bool LinSolver::LinSetSol(double* X){

	bool stat = false;
	if (LinSolvMet ==1){
		if(!Met_lu(X)){ return stat;}	
	}else if (LinSolvMet==2){
		if(!Met_bicgstab(X)){  return stat;}
	}else if(LinSolvMet==3){
		if(!Met_klu(X)){return stat;}
	}else{
		return stat;
	} 

	stat = true;
	return stat;
 }

