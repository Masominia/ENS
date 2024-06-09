#! /usr/bin/python3

import sh
import sys
import re
import Name
import NetPlot

def Plot(path):
	NetPlot.net_plot(path+'/temp.xml',path+'/temp/start.inp')

def Train(path):

	vol_file = open(path+'/temp/volt.inp','w')
	res_file = open(path+'/temp/resist.inp','w')

	print('in Train vol_count =',vol_count)

	fname = input('For training I need a file, let me have its address ' )
	print('I am going to train '+fname+' file')
	out_num = input('which output should be turn on for this? ')

	f_stat = False
	try:
		fp =open(fname,'r')
		f_stat = True		
	except:
		print("error in opening "+fname+" file")

	if f_stat:
		for i in range(1,vol_count+1):
			vs = fp.readline()
			vol_file.write(str(i)+'\t'+vs)
		vol_file.close()

		if out_num.lower() == 'all':
			for i in range(1,res_count+1):
				res_file.write(str(i)+'\t'+'1.0e-9\n')
		else:
			for i in range(1,int(out_num)):	
				res_file.write(str(i)+'\t'+'1.0e9\n')
			res_file.write(out_num+'\t'+'1.0e-9\n')
			for i in range(int(out_num)+1,res_count+1):	
				res_file.write(str(i)+'\t'+'1.0e9\n')
		res_file.close()
				
		Sim_time = int(input('How many times I should try? '))
		work_dir = path
		print('I am here; ',sh.pwd())
		print('Working directory is: ',work_dir)	
		RUN = sh.Command(work_dir+'/bin/ENS')
		print('\nStart training, please be patient ',end="",flush=True)
		for k in range(Sim_time):
			Res = RUN(work_dir+'/')
			print('.', end="", flush=True)

		print(Res)


		print('\ntraining of '+fname+' is finished\ngood luck')	

def Analyze(path):

	vol_file = open(path+'/temp/volt.inp','w')
	res_file = open(path+'/temp/resist.inp','w')

	fname = input('For analyzing I need the input file, please  give me ')
	print('I am going to analyze '+fname+' file')

	f_stat = False
	try:
		fp =open(fname,'r')
		f_stat = True		
	except:
		print("error in opening "+fname+" file")

	if f_stat:
		for i in range(1,vol_count+1):
			vs = fp.readline()
			vol_file.write(str(i)+'\t'+vs)
		vol_file.close()

		for i in range(1,res_count+1):
			res_file.write(str(i)+'\t'+'1.0e-9\n')

		res_file.close()
				
		work_dir = path
		RUN = sh.Command(work_dir+'/bin/ENS')
		print('\nStart Analyzing, please be patient ')
		Res = RUN(work_dir+'/')
		print(Res)


		print('\nAnalyzing of '+fname+' is finished\ngood luck')	

def command(cmd,path):

	
	known_cmds = {
		'train'  : Train,
		'analyze': Analyze,
		'plot' : Plot
	}

	if cmd in known_cmds.keys():
		known_cmds[cmd](path)
		
	else:
		print('Namana?\nCommand: "',cmd,'" is not defined')
def main(argv):

	global vol_count 
	global res_count

	Path = str(sh.pwd())
	Path = Path[:-1]
	Path += '/'
	name = Name.Name()
	Path += name
	print(Path)

	count_file = open(Path+'/temp/count.inp','r')

	vol_count = int(count_file.readline())
	res_count = int(count_file.readline())
	print(vol_count,'\t',res_count)
 	
	if len(argv) == 1:
		inp_file = sys.stdin	
	else:
		inp_file = open(argv[1],'r')
 	
	while True:
		inp_line = inp_file.readline()	
		inp_line = re.sub('\n','',inp_line)
		inp_line = inp_line.lower()
		if inp_line == 'sleep': 
			print('Good Night')
			break
		else:
			command(inp_line,Path)
			
if __name__ == '__main__':
    sys.exit(main(sys.argv))

