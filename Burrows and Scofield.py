f=input
x=sum(int(i)for i in f()if i.isdigit())
y=sum(int(j)for j in f()if j.isdigit())
print('"%d"'%sorted([x+y,x*y,abs(x-y)])[1])

