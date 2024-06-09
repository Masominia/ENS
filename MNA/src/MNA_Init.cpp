/*

		 Class Init as a member of MNA 
		written by Ehsan Nedaaee Oskoee
*/

#include "mnamatrix.h"

void MNA_Matrix::Init( ){

	rval +=1;
	uxtold +=1;

	delete [] rval;
	delete [] uxtold;

	mna +=1;
	delete [] mna;

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

	fvec +=1;
	delete [] fvec;
	size  = 81;
	len_max = 235;

	rval = new double [size];
	uxtold = new double [size];

	rval -=1;
	uxtold -=1;

	fvec = new double [size];
	fvec -=1;
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

	mna  = new vec<double> [size];
	mna -= 1;

	for(int i=1; i<=size; i++){
		mna[i].resize(0);
		rval[i] = 0.;
		uxtold[i] = 0.;
	}

}
