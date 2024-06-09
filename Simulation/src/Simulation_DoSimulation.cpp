/*
	Class member DoSimulation  of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"


 bool simulation::DoSimulation(std::string path){
cout<<"DoSim0\n";
 bool stat = false;
 int NumSim, analyze;	
 std::string path_file;	
//cout<<"Path in DoSimulation is: "<<path<<endl;
 path_file =path + "/temp/simulation.inp";
 ifstream load_simu(path_file.c_str());


 if(load_simu.good()){

	load_simu>>NumSim;

	for (int i =1; i<=NumSim; i++){

		load_simu>>analyze;

		switch(analyze){


		case 2:
			if(!AC_Analyse()){
				Error +="\n error in doing AC analyze\n";
				return stat;
			}
			break;
		case 501:
			if(!DC_Analyse(load_simu,path)){
				Error +="\n error in doing DC Sweep\n";
				return stat;	
			}
			break;
		case 502:
			if(!DC_Sweep(load_simu,path)){
				Error +="\n error in doing DC Sweep\n";
				return stat;	
			}
			break;
		case 503:
			if(!DC_Dynamic(load_simu,path)){
				Error +="\n error in doing DC Dynamic\n";
				return stat;
			}
			break;
		default:
			Error +="\n error in simulation: simulation code is not in the list\n";
			return stat;
	}//switch	

	stat = true;

	
	}//for loop

  }else{

	Error +="\n error in loading file "+path_file+" in DoSimulation\n";

 }	

cout<<"DoSimulation, end\n";
	return stat;
}
