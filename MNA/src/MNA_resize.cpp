/*
	Member resize of the class MNA_Matrix
	Tha action of this function is resizing 
	the sparse matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::Resize(int n){

	L1 +=1;
	L2 +=1;
	R1 +=1;
	R2 +=1;

	delete [] L1;
	delete [] L2;
	delete [] R1;
	delete [] R2;
		
	delete [] Ap;
	delete [] Ai;
	delete [] Ax;


	for(int i=1; i<=size; i++) {
		mna[i].resize(n);
	}

	
	len_max = 0;
	for(int i=1; i<=size; i++) len_max += mna[i].size();

	L1 = new int [len_max];
	L2 = new int [len_max];
	R1 = new int [len_max];
	R2 = new int [len_max];
		
	L1 -=1;
	L2 -=1;
	R1 -=1;
	R2 -=1;

	Ap = new int [size+1];
	Ai = new int [len_max];
	Ax = new double[len_max];



}


