def add_ind(a,i,j):
	if i in a.keys():
		if j not in a[i]:
			a[i].append(j)
	else:
		a[i] = [j]

