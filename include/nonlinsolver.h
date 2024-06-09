#include "elec_neuron.h"
#include "mnamatrix.h"
#include "linsolver.h"

#pragma once
#ifndef NONLINSOLVER_H_
#define NOLLINSOLVER_H_

 class NonLinSolver: public LinSolver {
 private:
	int nlnp;
	double TOLF, TOLMIN, TOLX, STPMX, ALF ;
	int MAXITS;
	double *nlg, *nlxold, *nlbx;
	bool check;

 public:
	NonLinSolver (int a = 1) : LinSolver(){

		MAXITS = 2000;
		TOLF = 1.0e-4;
		TOLMIN = 1.0e-6;
		TOLX = 1.0e-7;	
		STPMX = 100.0;
		ALF = 1.0e-4;
		check = false;

		nlnp = a;
		
		nlg 	= new double [nlnp];
		nlxold	= new double [nlnp];
		nlbx 	= new double [nlnp];
	
	
		
		nlg 	-= 1;
		nlxold 	-= 1;
		nlbx 	-= 1;



	}	
	
	~NonLinSolver (){
	
		nlg 	+= 1;
		nlxold 	+= 1;
		nlbx 	+= 1;



		delete [] nlg;
		delete [] nlxold ;
		delete [] nlbx;



	}


	void NonLinInit(int);
	bool mnewt(double *);
	void Do_Step_Limit(double*, double*);
	bool newt(double *);
	bool lnsrch(double*, double, double*, double*, double*, double*, double);
	double fmin(double *);
	void NonLinFvec(double *);
	void fdjac(double *);
	bool NonLinSetSolve(double*);
 };
#endif
