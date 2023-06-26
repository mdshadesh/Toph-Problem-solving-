a, b, c, d = [int(i) for i in input().split()]

if a == 1:
    print("YES")
elif (b + c + d) > 1:
    print("YES")
else:
    print("NO")
