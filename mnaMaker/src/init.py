def PrintInit(ind,path,Size):

	ff = path+'/MNA/src/MNA_Init.cpp'
	fp =  open(ff,'w') 

	fp.write('/*\n\n\t\t Class Init as a member of MNA \n\t\twritten by Ehsan Nedaaee Oskoee\n*/\n\n')
	fp.write('#include "mnamatrix.h"\n\n')
	fp.write('void MNA_Matrix::Init( ){\n\n')

	fp.write('\trval +=1;\n\tuxtold +=1;\n\n\tdelete [] rval;\n\tdelete [] uxtold;\n\n\tmna +=1;\n\tdelete [] mna;\n\n')
	fp.write('\tL1 +=1;\n\tL2 +=1;\n\tR1 +=1;\n\tR2 +=1;\n\n\tdelete [] L1;\n\tdelete [] L2;\n\tdelete [] R1;\n\tdelete [] R2;\n\n')

	fp.write('\tdelete [] Ap;\n\tdelete [] Ai;\n\tdelete [] Ax;\n\n')
	fp.write('\tfvec +=1;\n\tdelete [] fvec;\n')
	lenMax = 0
	for k in ind.keys():
		lenMax += len(ind[k])


	fp.write('\tsize  = '+Size+';\n')
	fp.write('\tlen_max = '+str(lenMax)+';\n\n')

	
	fp.write('\trval = new double [size];\n\tuxtold = new double [size];\n\n\trval -=1;\n\tuxtold -=1;\n\n')
	fp.write('\tfvec = new double [size];\n\tfvec -=1;\n')
	fp.write('\tL1 = new int [len_max];\n\tL2 = new int [len_max];\n\tR1 = new int [len_max];\n\tR2 = new int [len_max];\n\n')
	fp.write('\tL1 -=1;\n\tL2 -=1;\n\tR1 -=1;\n\tR2 -=1;\n\n')
	fp.write('\tAp = new int [size+1];\n\tAi = new int [len_max];\n\tAx = new double[len_max];\n\n')

	fp.write('\tmna  = new vec<double> [size];\n\tmna -= 1;\n\n')
	fp.write('\tfor(int i=1; i<=size; i++){\n\t\tmna[i].resize(0);\n\t\trval[i] = 0.;\n\t\tuxtold[i] = 0.;\n\t}\n\n')
	fp.write('}\n')

