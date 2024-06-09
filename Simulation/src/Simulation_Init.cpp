/*
	Member Init of the class Simulation
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "simulation.h"

 void simulation::Init(std::string path){

	int ir, Prt1, Prt2;
	double val;
	Error = "";
	std::string inp_start, inp_res, inp_vol;
/*
	path +="/temp/start.inp";
  	char *path_file;
  	path_file = new char[path.size()];

	for (unsigned int i=0; i<path.size(); i++) path_file[i] = path[i];
	  ifstream load_init(path_file);
*/

	inp_start = path + "temp/start.inp";
	inp_res = path + "temp/resist.inp";
	inp_vol = path + "temp/volt.inp";

//cout<<"in simulation init, inp_start is: "<<inp_start<<", inp_res is: "<<inp_res<<", inp_vol is: "<<inp_vol<<endl;
	ifstream load_init(inp_start.c_str());
	ifstream load_res(inp_res.c_str());
	ifstream load_vol(inp_vol.c_str());
//cout<<"SimInit0\n";

	MNA_Matrix::Init();
//cout<<"SimInit1\n";
	LinSolver::Init(size);
//cout<<"SimInit2\n";
        NonLinSolver::NonLinInit(size);
//cout<<"SimInit3\n";


	ux +=1;
	delete [] ux;
//cout<<"SimInit4\n";
	ux = new double [size];
	ux -=1;
	for(int i=1; i<=size; i++) ux[i] = 0.;
//cout<<"SimInit5\n";

  	if(load_init.good()){

	  load_init.seekg(0,load_init.end);
            if (load_init.tellg() != 0){
		load_init.clear();
		load_init.seekg(0,load_init.beg);

		for(;;){
			if(load_init.eof()) break;

			load_init>>ir>>Prt1>>Prt2>>val;
//cout<<ir<<'\t'<<Prt1<<'\t'<<Prt2<<'\t'<<val<<endl;
			uxtold[ir] = val;
			ux[ir] = val;
			Ch0(ir) = val;
			Ch_P1(ir) = Prt1;
			Ch_P2(ir) = Prt2;
			
		}
	   }	
	}
//cout<<"SimInit6\n";
	ir = 0;
	val = 0.0;
  	if(load_res.good()){
	  load_res.seekg(0,load_res.end);
	     if(load_res.tellg() != 0){
		load_res.clear();
		load_res.seekg(0,load_res.beg);

		for(;;){
			if(load_res.eof()) break;
			load_res>>ir>>val;
			R(ir) = val;
//cout<<"R "<<ir<<" = "<<R[ir]<<endl;
		}
	   }
	}
	ir = 0;
	val = 0.0;
  	if(load_vol.good()){
	  load_vol.seekg(0,load_vol.end);
	     if(load_vol.tellg() != 0){
		load_vol.clear();
		load_vol.seekg(0,load_vol.beg);

		for(;;){
			if(load_vol.eof()) break;
			load_vol>>ir>>val;
			Vs(ir) = val;
//cout<<"Vs "<<ir<<" = "<<Vs[ir]<<endl;
		}
	    }

	}

 }

