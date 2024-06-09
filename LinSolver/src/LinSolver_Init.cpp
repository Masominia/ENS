/*
	Member linbcg of the class LinSolver
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "linsolver.h"

 void LinSolver::Init(int a)
 {
	p  += 1;
        pp += 1;
        r  += 1;
        rr += 1;
        z  += 1;
        zz += 1;
	h  += 1; 


        delete [] p;
        delete [] pp;
        delete [] r;
        delete [] rr;
        delete [] z;
        delete [] zz;
	delete [] h;

	delete [] BB;

	np = a;

	p  = new double[np];
	pp = new double[np];
	r  = new double[np];
	rr = new double[np];
	z  = new double[np];
	zz = new double[np];
	h  = new double[np];


	p  -= 1;
	pp -= 1;
	r  -= 1;
	rr -= 1;
	z  -= 1;
	zz -= 1;
	h  -= 1;
	
	BB = new double[np];

 }
