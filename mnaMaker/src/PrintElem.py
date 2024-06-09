def NumGen(Name,grp,ind):

	Comp = {
		'R'  : '001',
		'C'  : '002',
		'L'  : '003',
		'V'  : '004',
		'I'  : '005',
		'Vt' : '006',
		'It' : '007',
		'D'  : '501',
		'QN' : '502',
		'QP' : '503',
		'CCM': '504',
		'NC' : '505',
		'VCM': '506',
		'VMS': '507',
		'CMS': '508'
	}
	
	return ind+str(grp)+Comp[Name]


def PrintElement(self, path):

	fp = open(path,'w')
	fp.write(str(self.NumNode)+'\n')
	fp.write(str(self.NumElem)+'\n')
	fp.write(str(self.NumG2)+'\n')
	fp.write(str(self.NumNonLinElem)+'\n')

	elist=[e for e in self.Elem]

	for name in elist:
		Grp = 1
		if isinstance(self.Elem[name],list):
			for i in self.Elem[name]:
				Grp = 1
				if 'Group' in i.keys(): Grp = 2
				fp.write(NumGen(name,Grp, i['@index'])+'\n')
		else:
			if 'Group' in self.Elem[name].keys(): Grp = 2
			fp.write(NumGen(name, Grp,self.Elem[name]['@index'])+'\n')

