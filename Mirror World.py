for i in[*open(0)][1:]:
    a,b=i.split();c,d=int(a[::-1]),int(b[::-1]);print(a,c==d and"="or c>d and">"or"<",b)
