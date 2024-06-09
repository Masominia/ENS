/*
	Class member DC_Analyse  of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"

 bool simulation::AC_Analyse(){

	bool stat = false;
	if (!LinSetSol(ux)) {Error += "\n Error in solving linear set of equations:\n"; return stat;}

	stat = true;
	return stat;
 }

