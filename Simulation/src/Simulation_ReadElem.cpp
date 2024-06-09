/*
	Class member ReadElements of the class simulation
	written by Ehsan Nedaaee Oskoee
	
*/


#include "simulation.h"


bool simulation::ReadElements(std::string path)
{
  bool stat = false;
  std::string path_file;	

  path_file =path + "/temp/elements.inp";
  ifstream load_elems(path_file.c_str());

  if(load_elems.good()){
	
	load_elems>>NumNode;
	load_elems>>NumElem;
	load_elems>>NumG2;
	load_elems>>NumNonLinElem;

	Elm +=1;
	delete Elm;
	Elm = new int [NumElem];
	Elm -=1;

	for(int i=1; i<=NumElem; i++) load_elems>>Elm[i];
/*
	NumNonLinElem = 0;
	for(int i=1; i<=NumElem; i++) {if( Elm[i]%1000>=500) NumNonLinElem++;}
*/
	stat = true;
  }  
 return stat;
}
