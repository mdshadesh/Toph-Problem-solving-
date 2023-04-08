for x in range(int(input())):
	s=input()
	us=set(s)
	print("Case #%d:"%(x+1))
	for i in us:
		print(i,s.count(i))
