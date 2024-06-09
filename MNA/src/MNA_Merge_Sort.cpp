/*
	Member Merge_Sort of the class MNA_Matrix
	Tha action of this function is resizing 
	the sparse matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::Merge_Sort(int *A, int *B, int p , int r)
 {
	int q;

	if(p<r){

		q = (p+r)/2;

		Merge_Sort(A,B,p,q);
		Merge_Sort(A,B,q+1,r);
		
		Merge(A,B,p,q,r);
	}

 }
