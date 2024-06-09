from Stamp import ResistorStamp, CapacitorStamp, VoltageStamp, DiodeStamp, DVoltageStamp,\
		CCMemristorStamp,PNPStamp,NPNStamp, NonLinCapStamp, CurrentStamp, DCurrentStamp,\
		VCMemristorStamp,VMSStamp,CMSStamp
import init



def MakeMatrix(self,path):

	dispatch = {
		'R'  : ResistorStamp.ResistorStamp,
		'C'  : CapacitorStamp.CapacitorStamp,
		'V'  : VoltageStamp.VoltageStamp,
		'I'  : CurrentStamp.CurrentStamp,
		'D'  : DiodeStamp.DiodeStamp,
		'It' : DCurrentStamp.DCurrentStamp,
		'Vt' : DVoltageStamp.DVoltageStamp,
		'CCM': CCMemristorStamp.CCMemristorStamp,
		'VCM': VCMemristorStamp.VCMemristorStamp,
		'VMS': VMSStamp.VMSStamp,
		'CMS': CMSStamp.CMSStamp,
		'QP' : PNPStamp.PNPStamp,
		'QN' : NPNStamp.NPNStamp,
		'NC' : NonLinCapStamp.NonLinCapStamp
	}	

	ff = path+'/MNA/src/MNA_Make.cpp'
	fp =  open(ff,'w') 

	elist=[e for e in self.Elem]


	fs = path+'/temp/start.inp'
	ft = path+'/temp/volt.inp'

	fn = open(fs,'w')	
	fv = open(ft,'w')	

	fp.write('/*\n\n\t Class Make as a member of MNA \n\n\twritten by Ehsan Nedaaee Oskoee*/\n\n')
	fp.write('#include "mnamatrix.h"\n\n')
	fp.write('void MNA_Matrix::Make(double *Vx){\n\n \tdouble idt;\n \tif(Delt > 0.)  idt = 1./Delt;\n')
	fp.write('\tfor(int i=1; i<=size; i++) {\n\t\tfor(int j=1; j<=mna[i].size(); j++) mna[i](mna[i].row(j))=0.;\n\t\trval[i] = 0.;\n')
	if self.NumNonLinElem > 0: fp.write('\t\tfvec[i]=0.;\n')
	fp.write('\t}\n')
	


	for name in elist:

		if isinstance(self.Elem[name],list):
			for i in self.Elem[name]:
				dispatch[name](i,self.Model,fp,self.index,self.NumNonLinElem,fn,fv)
		else:
			i=self.Elem[name]
			dispatch[name](i,self.Model,fp,self.index,self.NumNonLinElem,fn,fv)

#	fp.write('\n\tif(tt_M==0) tt_M =1;\n')	
	fp.write('}')	
	
	len_max = 0
#	print('size =',len(self.index))
	for k in self.index.keys():
		len_max += len(self.index[k])
#		print(k,self.index[k],'\t with size',len(self.index[k]))
#	print('\n len_max = ',len_max)
	
	init.PrintInit(self.index,path,str(self.NumNode +self.NumG2))
