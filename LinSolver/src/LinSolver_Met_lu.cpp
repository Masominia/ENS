/*
	Class member Met_lu  of the class linsolver
	written by Ehsan Nedaaee Oskoee
	
*/


#include "linsolver.h"

 bool LinSolver::Met_lu(double* X){

	bool stat = false;
	int nx = np; //NumNode+NumG2;

	double **mm;
 	double *b,p; 
	int *index;

	b = new double [nx];
	b -=1;
	
	index = new int [nx];
	index -=1;

	mm = new double* [nx+1];
	mm -=1;
	mm[1] = new double [nx*nx+1];
	for(int i=2; i<=nx; i++){
		mm[i] = mm[i-1]+nx;
	}

	for(int i=1; i<= nx; i++)
		for(int j=1; j<=nx; j++)
			mm[i][j] = 0.;//i*100+j; 

	for(int i = 1; i <= size; i++) 
		for(int j=1; j<=size; j++) mm[i][j] = mna[i][j];
		
	

	for(int i=1; i<=nx; i++){
		b[i] = rval[i];
		index[i] = 0;
	}

	ludcmp(mm,size,index,&p);
	lubksb(mm,size,index,b);

	for(int i=1; i<=nx; i++) X[i] = b[i];
	
	b +=1;
	delete [] b;

	index +=1;
	delete [] index;

	stat = true;
	return stat;
 }

