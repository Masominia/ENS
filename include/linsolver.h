#include "elec_neuron.h"
#include "mnamatrix.h"


#pragma once
#ifndef LINSOLVER_H_
#define LINSOLVER_H_

 class LinSolver: public MNA_Matrix {
 private:
	int np;

	double EPS;
	double *p,*pp,*r,*rr,*z,*zz,*h;
	double *BB;

 protected:	
 	//double *ux;
	int LinSolvMet;

 public:
	LinSolver(int a=0):MNA_Matrix(){

		np = a;
		EPS = 1.e-20;
		LinSolvMet = a;

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
		h -= 1;	
		
		BB = new double[np];
	
	}
	
	~LinSolver(){

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

	}		

	void Transpose();
	void linbcg(double*, int, double, int, int*, double*);
	void asolve(double*, double*, int );
	void sprsax(double*, double*);
	void sprstx(double*, double*);
	void atimes(double*, double*, int);
	double snrm(double*, int);
	double ddot(int, const double*, int, const double*, int );
	void dcopy(int, const double*, int, double*, int );
	void daxpy(int, double, const double*, int, double*, int );
	void dscal(int, double, double*, int );
	int bicgstab( double*, double, bool );
	void Init(int);
	void lubksb(double**, int, int*, double[]);
	void ludcmp(double**, int, int*, double*);
	bool LinSetSol(double*);
	bool Met_bicgstab(double*);
	bool Met_lu(double*);
	bool Met_klu(double*);


 };


#endif

