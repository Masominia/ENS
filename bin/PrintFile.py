import sh

def PrintFile(ReadFile, output,col):

	methodfile = open('method.mtd','w')
	if col =='':
		methodfile.write('0')
	else:
		k=col.split(':')
		methodfile.write(str(len(k))+'\n')
		for j in k:
			methodfile.write(j+'\n')
	methodfile.close()
	Read = sh.Command('bin/read_file')
	if output == '':
		print(Read(ReadFile,'method.mtd'))
	else:
		print(Read(ReadFile,'method.mtd',output))	
	sh.rm('method.mtd')

