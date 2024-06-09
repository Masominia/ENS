/*
	Class member DC_Sweep  of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"

 bool simulation::DC_Dynamic(ifstream& fin, std::string path){

	bool stat = false;
	double dynamic_val;
	double start_point, step_val, stop_point;	
	int output_rate;
	std::string output_file;
	int Kt, ParamNo, Parameter;


	fin>>ParamNo;

	for(int i=1; i<=ParamNo; i++){

		fin>>Parameter;

		switch(Parameter){

		case 1:
			fin>>LinSolvMet;	
			break;
		case 2:
			fin>>start_point;
			break;
		case 3:
			fin>>step_val;
			break;
		case 4:
			fin>>stop_point;
			break;
		case 5:
			fin>>output_file;
			break;
		case 6:
			fin>>output_rate;
			break;
		default:
			Error +="\n error in simulation: simulation code is not in the list\n";
			return stat;
		}//switch	
	}
	Delt = step_val;
	output_file = path+"/"+output_file;

	if(NumNonLinElem>0){
	
		for(int i=1; i<=size; i++) uxtold[i] = ux[i];
		PrintFile(output_file,start_point,0, "time");
		Kt = 0;

		for(dynamic_val = start_point; dynamic_val<=stop_point; dynamic_val += step_val){	
			tm = dynamic_val;

			Make(ux);

			Kt++;
			if (NonLinSetSolve(ux)){Error +="\n Failed to solve the nonlinear set of equation:\n"; return stat;}
			if(Kt%output_rate==0) PrintFile(output_file,dynamic_val,1, "time");

			for(int i=1; i<=size; i++) uxtold[i] = ux[i];

		}
	}else{


		for(int i=1; i<=size; i++) uxtold[i] = ux[i];
		PrintFile(output_file,start_point,0, "time");
		Kt = 0;
		for(dynamic_val = start_point; dynamic_val<=stop_point; dynamic_val += step_val){
			tm = dynamic_val;
			Make(ux);
			Kt++;
			if (!LinSetSol(ux)) {Error += "\n Error in solving linear set of equations:\n"; return stat;}
			if(Kt%output_rate==0) PrintFile(output_file,dynamic_val,1, "time");
			for(int i=1; i<=size; i++) uxtold[i] = ux[i];
		}
 	}


	stat = true;
	return stat;
 }

