/*
	Class member PrintFile of the class simulation
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "simulation.h"


inline int group(int a){
	return (int(a%10000)-int(a%1000))/1000;
}

inline int index(int a) {return int(a/10000); }

std::string kind(int a){

	switch(int(a%1000)){
		case 1:
			return "R";
			break;
		case 2:	
			return "C";
			break;
		case 3:
			return "L";
			break;
		case 4:
			return "V";
			break;
		case 5:
			return "I";
			break;
		case 6:
			return "Vt";
			break;
		case 7:
			return "It";
			break;
		case 501:
			return "D";
			break;
		case 502:
			return "QN";
			break;
		case 503:
			return "QP";
			break;
		case 504:
			return"CCM";
			break;
		case 505:
			return"NC";
			break;
		case 506:
			return"VCM";
			break;
		case 507:
			return"VMS";
			break;
		case 508:
			return"CMS";
			break;
		default:
			return "";
		
	}
	
	
}

 bool simulation::PrintFile(std::string fout, double t, int tt, std::string param_name)
 {


 std::string kx;

 string s;
 bool stat = false;
 string output_meta;
 string output_data;	
 int num_total;
 output_meta = fout;
 output_data = fout;
 output_meta += ".meta";
 output_data += ".data";

//cout<<"simulation output_meta is: "<<output_meta<<" and fout is: "<<fout <<endl;
	ofstream out_m(output_meta.c_str(),ios::app);
	ofstream out_d(output_data.c_str(), ios::app | ios::binary);

	num_total = NumNode+NumG2+1;

	if(tt==0) {

		out_m<<param_name<<"\t";
		for(int k=1; k<=NumNode; k++){

			out_m<<" V(N"<<k<<")\t";
		}

		for(int i =1;i<=NumElem; i++){

			if(group(Elm[i])==2){
				out_m<<"I("<<kind(Elm[i])<<index(Elm[i])<<")\t";
			}
		}
		out_m<<"\n\n";
		
		out_d.write(reinterpret_cast<char*>(&num_total),sizeof(int)); // write int to binary file
		out_d.write(reinterpret_cast<char*>(&t),sizeof(double)); // write int to binary file
		out_d.write(reinterpret_cast<char*>(&ux[1]),(NumNode+NumG2)*sizeof(double)); // write int to binary file
	}else{

		out_d.write(reinterpret_cast<char*>(&t),sizeof(double)); // write int to binary file
		out_d.write(reinterpret_cast<char*>(&ux[1]),(NumNode+NumG2)*sizeof(double)); // write int to binary file

	}	

	stat = true;
	return stat;
							


}
