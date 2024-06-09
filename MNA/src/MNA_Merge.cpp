/*
	Member Merge of the class MNA_Matrix
	Tha action of this function is resizing 
	the sparse matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::Merge(int *A, int *B, int p ,int q, int r)
 {
	int i,j;
	
	int n1 = q - p +1;
	int n2 = r - q;
	
	for(i=1; i<=n1; i++){

		L1[i] = A[p+i-1];
		L2[i] = B[p+i-1];
	}

	for( j=1; j<=n2; j++){
		
		R1[j] = A[q+j];
		R2[j] = B[q+j];	
	} 

	L1[n1 + 1] = INT_MAX;
	R1[n2 + 1] = INT_MAX;
	
	i = 1;	
	j = 1;
	
	for(int k = p; k<= r; k++){
		
		if(L1[i]<=R1[j]){
			A[k] = L1[i];
			B[k] = L2[i];
			i++;
		}else{
			A[k] = R1[j];	
			B[k] = R2[j];
			j++;
		}
	}
 }


