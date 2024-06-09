/*
	Class member printwhole of the class MNA_Matrix
	written by Ehsan Nedaaee Oskoeee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::PrintWhole(){

	cout.setf(ios_base::left, ios_base::adjustfield);


	cout<<"\n  the mna matrix is :\n\n";
	for(int i=1; i<=size; i++){
		cout<<"| ";
		for(int j=1; j<=size; j++){
			cout.precision(3);
                        cout.width(6);

			cout<<mna[i][j]<<'\t';

		}

		cout.precision(4);
                cout.width(7);
		cout<<" ||"<<rval[i]<<"\t|\n";
	}
 }

