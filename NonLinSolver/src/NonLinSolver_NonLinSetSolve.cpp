/*
	Member NonLinSetSolve of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee, based on
	routine newt of Numerical Recipes book
	
*/


#include "nonlinsolver.h"
#include "random.h"

 bool NonLinSolver::NonLinSetSolve(double *XX)
 {


	bool stat = newt(XX);

	Random rnd;
	long int iseed;
	iseed = 52L;
	int k = 1;
//cout<<stat<<endl;
	while(!stat){

//		cout<<"non linear solver converged on local minimum, I'm trying new starting point:\n\n";	
		for(int i=1; i<=nlnp; i++) XX[i] += 1.e-6*rnd.gasdev(&iseed);	

		stat = newt(XX);

		k++;
		if (k>10) cout<<"I have  passed the maximum, try for different starting point\n"; break;
	
	}

	return stat;
 }
