/*
	Member ResetW of the class MNA_Matrix
	The action of this function is resetting
	the total matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::ResetW()
{
	for(int i=1; i<=size; i++) mna[i].resize(0);
//		for(int j=1; j<=mna[i].size(); j++) mna[i](mna[i].row(j)) = 0.;

	for(int k=1; k<=size; k++) {rval[k] = 0.; fvec[k] = 0.;}

}
