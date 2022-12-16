for t in range(int(input())) :
 s=input();print('Case %d: %d'%(t+1,s[s.find('1')+1:].count('01')))
 