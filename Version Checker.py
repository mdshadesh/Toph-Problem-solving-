x, y = input().split()
m, n = x.split("."), y.split(".")
for i, j in zip(m, n):
    if int(i) == int(j):
        continue
    if int(i) > int(j):
        print(x)
        break
    else:
        print(y)
        break
