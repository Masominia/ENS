def NumGen(param):
	
	Param = {
		'method' : '001',
		'start' : '002',
		'step' : '003',
		'end' : '004',
		'output' : '005',	
		'output_rate' : '006',
		'source' : '007',
		'text' : '000'		
	}

	return Param[param]

def CodeGen(Name):
	
	code = {
		'DC_Analyze' : '501',
		'DC_Sweep'   : '502',
		'DC_Dynamic' : '503'
	}

	return code[Name]
def ValGen(k):
	
	t = ''
	if isinstance(k,str):
		if k.lower() == 'lu':
			t = '1'
		elif k.lower() =='bicgstab':
			t = '2'
		elif k.lower() =='klu':
			t = '3'
		else:
			t = k
	else:
		t = str(k)
	return t

def PrintSimulation(self, path):

	fp = open(path,'w')

	SimNum = len(self.Simu)
	fp.write(str(SimNum)+'\n')

	for k in self.Simu.keys():
		size = len(self.Simu[k])
		if '#text' in self.Simu[k].keys() : size -=1 
		fp.write(CodeGen(k)+'\n'+str(size)+'\n')
		for v in self.Simu[k]:
			if v != '#text':
				fp.write(NumGen(v.replace("@","").replace("#",""))+'\n')
				fp.write(ValGen(self.Simu[k][v])+'\n')

