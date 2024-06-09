def file_count(fname):

	fp = open(fname,'r')
	
	cnt = 0
	for line in fp: cnt +=1

	return cnt

