/*
	Class member print of the class MNA_Matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::Print(){
	cout<<"MNA Matrix is:\n\n";
	
	for(int i =1; i<=size; i++){
		for(int j=1; j<=mna[i].size(); j++) cout<<mna[i][mna[i].row(j)]<<'\t';
		cout<<'\n';
	}
				
 }


