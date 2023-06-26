t = int(input())

for _ in range(t):
    n = int(input())

    s = ["   ##########", "  #        #", " #        #", "##########"]
    s1 = [" ##########", " #        #", " #        #", " ##########"]

    for _ in range(n-1):
        for k in range(4):
            s[k] += s1[k]

    for k in range(4):
        print(s[k])
