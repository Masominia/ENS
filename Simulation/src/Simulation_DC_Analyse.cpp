/*
	Class member DC_Analyse  of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"

 bool simulation::DC_Analyse(ifstream& fin, std::string path){

	bool stat = false;
	std::string output_file;
	int ParamNo, Parameter;

	fin>>ParamNo;

	for(int i=1; i<=ParamNo; i++){

		fin>>Parameter;

		switch(Parameter){

		case 1:
			fin>>LinSolvMet;	
			break;
		case 5:
			fin>>output_file;
			break;
		default:
			Error +="\n error in simulation: simulation code is not in the list\n";
			return stat;
		}//switch	
	}

	output_file = path+"/"+output_file;
	Make(ux);
	if(NumNonLinElem>0){
		if (! NonLinSetSolve(ux)){cout<<"\n Nonlinear solver converged globally:\n";}// return stat;}
	}else{
		if (!LinSetSol(ux)) {Error += "\n Error in solving linear set of equations:\n"; return stat;}
 	}

	PrintFile(output_file,0.0,0, "DC_Analyze");

//	for(int i =1; i<=size; i++) cout<<ux[i]<<'\t';
//	cout<<endl;

	stat = true;
	return stat;
 }

