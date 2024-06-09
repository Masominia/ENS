#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;


int main(int argc, char **argv)
{


 int row;
 double* A;
 int *met, noMet;

 std::string line;
 std::string res_meta, res_data;
 res_meta = argv[1];
 res_meta +=".meta";
 res_data = argv[1];
 res_data +=".data";

  std::ifstream loadmeta(res_meta.c_str());	
  std::ifstream loadfile(res_data.c_str(), std::ios_base::binary);
  std::ifstream method(argv[2]);

  std::streambuf * buf;
  std::ofstream of;
  if(argc>3) {
    	of.open(argv[3]);
	buf = of.rdbuf();

  } else {
    	buf = std::cout.rdbuf();
  }
  std::ostream out(buf);

  method>>noMet;
  
  if(noMet>0){
	met = new int [noMet];
	met -=1;
	for (int i =1; i<=noMet; i++) method>>met[i];
  }
	

  if(loadmeta.good()){
	cout<<"Meta data is:\n";
	getline(loadmeta,line);
	cout<<line<<endl;
  }

  if(loadfile.good())
  {
	loadfile.read(reinterpret_cast<char*>(&row), sizeof(int));	
	cout<<"Nomber of Column = "<<row<<endl;
	A = new double [row];
	A -=1;
	do{
		loadfile.read(reinterpret_cast<char*>(&A[1]), row*sizeof(double));
		if(!loadfile.eof()){
			if(noMet>0){
				for(int i=1; i<=noMet; i++) out<<A[met[i]]<<'\t';
				out<<'\n';
			}else{
				for (int i=1; i<=row; i++) out<<A[i]<<"\t";
				out<<"\n"; 
			}
		}
	}while(!loadfile.eof());
  }

  return 0;
}
