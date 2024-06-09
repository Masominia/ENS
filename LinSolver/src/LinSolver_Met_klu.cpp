/*
	Class member Met_klu  of the class linsolver.h
	written by Ehsan Nedaaee Oskoee
	
*/


#include "linsolver.h"

 bool LinSolver::Met_klu(double* X){

	bool stat = false;

	klu_defaults (&Common) ;

	int k =0;

        for(int i=0;i<=size;i++) Ap[i]=0;

        for(int j=1; j<=size; j++){
                for(int i=1; i<=size; i++){
                        if(mna[i].jcheck(j)>0){
                                Ap[j] +=1;
                                Ai[k] = i-1;
                                Ax[k] = mna[i][j];
                                k++;

                        }
                }
                Ap[j] += Ap[j-1];
        }





	for(int i=0; i<size; i++) BB[i] = rval[i+1];
//cout<<"in met klu, BB[1] is: "<<BB[1];
	
	Symbolic = klu_analyze (size, Ap, Ai, &Common) ;
	Numeric = klu_factor (Ap, Ai, Ax, Symbolic, &Common) ;

	klu_solve (Symbolic, Numeric, size, 1, BB, &Common) ;

	for(int i=1; i<=size; i++) X[i] = BB[i-1];
//cout<<" and after operation, BB[5] is: "<<BB[5]<<endl;
	klu_free_symbolic (&Symbolic, &Common) ;
	klu_free_numeric (&Numeric, &Common) ;

	
	stat = true;
	return stat;


 }



