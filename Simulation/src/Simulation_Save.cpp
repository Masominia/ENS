/*
	Member Save of the class Simulation
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "simulation.h"

 void simulation::Save(std::string path){

	std::string inp_start;
	inp_start = path + "temp/start.inp";
	ofstream save_init(inp_start.c_str());
	int ir;
/*
	path +="/temp/start.inp";
  	char *path_file;
  	path_file = new char[path.size()];

	for (unsigned int i=0; i<path.size(); i++) path_file[i] = path[i];
	  ofstream save_init(path_file,ios::out);
*/

cout<<"size of Ch0 is: "<<Ch0.size()<<endl;
cout<<"In the simulation path is: "<<inp_start<<endl;
  	if(save_init.good()){
		
		for(int i=1; i<=Ch0.size(); i++){
			ir = Ch0.row(i);
			save_init<<ir<<'\t'<<Ch_P1[ir]<<'\t'<<Ch_P2[ir]<<'\t'<<uxtold[ir]<<endl;
cout<<i<<'\t'<<Ch0.row(i)<<endl;
		}

	}

 }

