#include "elec_neuron.h"
#include "simulation.h"

int main(int argc, char *argv[]){

	simulation Simu;
	std::string Path;
	Path = argv[1];
	cout<<"The simulation path is:\n"<<Path<<endl;
	Simu.Init(Path);
	cout<<"Initialization has been done successfully,\n\t I'm going to read elements\n ";

	if(Simu.ReadElements(Path))
		cout<<"Reading elements has been done successfully\n\t I'm going to do simulation\n";

	if(Simu.DoSimulation(Path)) 
		cout<<"Simulation has been done successfully, snapshot is saving\n";
	Simu.Save(Path);
	cout<<"Errors in simulation are as follow:\n"<<Simu.ErrorReport()<<endl;
	return 0;
}
