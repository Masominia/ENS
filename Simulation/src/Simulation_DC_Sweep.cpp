/*
	Class member DC_Sweep  of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"

 bool simulation::DC_Sweep(ifstream& fin, std::string path){


	bool stat = false;
	int ParamNo, Parameter;
	double start_point, step_val, stop_point;	
	int output_rate;
	std::string output_file;
	std::string Source;
	int Kt;

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
		case 7:
			fin>>Source;
			break;
		default:
			Error +="\n error in simulation: simulation code is not in the list\n";
			return stat;
		}//switch	


	}

	output_file = path+"/"+output_file;

	if(NumNonLinElem>0){
		PrintFile(output_file,start_point,0, Source);
		Kt = 0;
		for(Sweep_Val = start_point; Sweep_Val<=stop_point; Sweep_Val += step_val){	
			Kt++;
			Make(ux);
			if (! NonLinSetSolve(ux)){cout<<"\n Nonlinear solver converged globally:\n";}// return stat;}
			if(Kt%output_rate==0) PrintFile(output_file,Sweep_Val,1, Source);
		}
	}else{
		Kt = 0;
		PrintFile(output_file,start_point,0, Source);
		for(Sweep_Val = start_point; Sweep_Val<=stop_point; Sweep_Val += step_val){	
			Kt++;
			Make(ux);
			if (!LinSetSol(ux)) {Error += "\n Error in solving linear set of equations:\n"; return stat;}
			if(Kt%output_rate==0) PrintFile(output_file,Sweep_Val,1, Source);
		}
 	}


	stat = true;
	return stat;
 }

