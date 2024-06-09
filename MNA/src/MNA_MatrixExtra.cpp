/*
	Class members of the class MNA_Matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"


 void MNA_Matrix::Set_Size(int a) { size = a;}
 void MNA_Matrix::Set_Rval(int i, double a) {rval[i] = a;}

	
 int MNA_Matrix::get_Size() {return size;}
 double MNA_Matrix::get_Rval(int i) {return rval[i];}
