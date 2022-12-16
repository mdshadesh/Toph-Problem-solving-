i=[]
while 1:
 try:x=input().split();i+=x
 except:break
print(max(set(i),key=i.count))

