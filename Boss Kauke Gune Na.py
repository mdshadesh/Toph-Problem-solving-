for t in[1]*int(input()):
    k=int(input().split()[1]);a=list(map(int,input().split()));x=a.pop(k-1);a.sort();a.insert(k-1,x);print(*a)
