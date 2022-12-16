t=int(input())
for T in range(t):
	a,b = map(int,input().split())
	c = [0]*102
	c[0]=a//b
	a = a%b
	if(a==0):
		print(c[0])
		continue 
	for i in range(1,102):
		a = a*10
		c[i]=a//b
		a %= b
	i=101
	if(c[i]>4):c[i-1]+=1
	while(i>0):
		if(c[i]>=10):c[i-1]+=1;c[i]-=10;
		i-=1
	j = 100
	while(c[j]==0):j-=1
	print(c[0],end="")
	print(".",end="")
	for i in range(1,j+1):print(c[i],end="")
	print()	

    