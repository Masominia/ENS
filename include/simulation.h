/*
	The main class of the circuit simulatior 
	Written by Ehsan Nedaaee Oskoee
*/

#include "elec_neuron.h"
#include "nonlinsolver.h"

#pragma once
#ifndef SIMULATION_H_
#define SIMULATION_H_

class simulation: public NonLinSolver {
 private: 

	int LineNo;
	std::string Error;

	double *ux;
	int *Elm;
	int *Sim;
	int NumNode;
	int NumElem;
	int NumSimu;
	int NumG2;
	int NumNonLinElem;

 public:
	simulation(int i = 0, int el=0, int sm=0, int ng=0, int nn=0, std::string s=""):NonLinSolver()
	{
		ux = new double[i];
              	ux -=1;
		
		NumElem = el;
		NumNode = ng;
		NumNonLinElem = nn;

		Elm = new int[NumElem];
		Elm -=1;

		NumSimu = sm;
		Sim = new int[NumSimu];
		Sim -=1;

		Error = s;

	}

	~simulation()
	{
		ux += 1;
		delete [] ux;     
		Elm +=1;
		delete Elm;
		Sim +=1;
		delete Sim;
		
	}



	bool ReadElements(std::string);

	bool PrintFile(std::string, double, int, std::string);
	std::string ErrorReport();
	int FileLine();

	void Init(std::string);
	bool DC_Analyse(ifstream&, std::string);
	bool AC_Analyse();
	bool DC_Sweep(ifstream&, std::string);
	bool DC_Dynamic(ifstream&, std::string);
	bool DoSimulation(std::string);
	void Save(std::string);
	


};

#endif


