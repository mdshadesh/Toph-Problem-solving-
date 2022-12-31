k=input
for i in[0]*k():
 a=k();b={1,a}
 for i in range(2,int(a**.5+1)):
  if a%i==0:b.update((i,a/i))
 c=sum(b);print 2 not in [c,2**c%c]and"No"or"Yes"