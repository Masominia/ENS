/*
	Class of MNA Matrix in the circuit 
	Written by Ehsan Nedaaee Oskoee
*/

#include "elec_neuron.h"
#include "dynamicarray.h"

#pragma once
#ifndef MNAMATRIX_H_
#define MNAMATRIX_H_

 class MNA_Matrix{
 
  protected:
	

	int size;
	int len_max;
	double Delt;
	double tm;
	double Sweep_Val;

	vec<double> *mna;

	vec<double> Ch0;
	vec<double> R;
	vec<double> Vs;
	
	vec<int> Ch_P1;
	vec<int> Ch_P2;
	
	double *rval;
	double *uxtold;

	int *L1, *L2, *R1, *R2;  // are used in MERGE-SORT method

	int *Ai;               	// Are used in klu
	int *Ap; 		// Are used in klu
	double *Ax; 		// Are used in klu
	double *fvec;

	klu_symbolic *Symbolic;
	klu_numeric *Numeric;
	klu_common Common;



  public:
	MNA_Matrix(int a=0, int s=0, double dt=0.){

		size = a;
		len_max = s;
		Delt = dt;
		tm = dt;

		rval = new double [size];
		rval -=1;


		uxtold = new double [size];
		uxtold -=1;

		mna  = new vec<double> [size];
		mna -= 1;
		

		L1 = new int [s];
		L2 = new int [s];
		R1 = new int [s];
		R2 = new int [s];
		
		L1 -=1;
		L2 -=1;
		R1 -=1;
		R2 -=1;

		Ap = new int [size+1];
		Ai = new int [len_max];
		Ax = new double[len_max];
		
		fvec = new double [size];
		fvec -=1;
//		Ch0.resize(s);
	}
	
	~MNA_Matrix(){

		rval +=1;
		delete [] rval;

		uxtold +=1;
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

		fvec += 1;
		delete [] fvec;

 	}

	void Set_Size(int);	
	void Set_Rval(int, double);

	int get_Size();	
	double get_Rval(int);

	void Make(double*);

	void Print();
	void PrintWhole();	

	void Resize(int);
	void ResetW();

	void Init();
	void Merge_Sort(int*, int*, int, int);
	void Merge(int*, int*, int, int, int);



 };

#endif


