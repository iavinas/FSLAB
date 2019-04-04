for _ in range(1,9):
	dir = 'lp' + str(_)
	print('mkdir ' + dir)
	print('cd '+ dir)
	print('touch ' + 'README.md')
	print('cd ..')