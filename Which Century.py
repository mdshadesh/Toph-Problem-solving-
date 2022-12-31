

for t in range(int(input())):
    y=int(input());x=y//100
    if y%100!=0:
        x+=1
        x=str(x)
        z="st"if x=="21"else"nd"if x=="22"else"rd"if x=="23"else"th"
        print(f"Case #{t+1}: {x}{z} century!")

