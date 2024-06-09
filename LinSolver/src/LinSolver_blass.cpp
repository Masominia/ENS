/*
	Members which emulating the blass routines for the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

double LinSolver::ddot( int n, const double *x, int incx, const double *y, int incy ) {
	double sum = 0.;
	for(int i = 1; i<=n; i++)
		sum += x[i]*y[i];
	return sum;
}

void LinSolver::dcopy( int n, const double *x, int incx, double *y, int incy ) {
	for(int i =1; i<=n; i++)
		y[i] = x[i];
}

void LinSolver::daxpy( int n, double alpha, const double *x, int incx, double *y, int incy ) {
	for(int i=1; i<=n; i++)
		y[i] += alpha*x[i];
}
void LinSolver::dscal( int n, double alpha, double *x, int incx ) {

	for(int i=1; i<=n; i++)
		x[i] *= alpha;
}
