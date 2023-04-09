n, r = map(int, input().split())
l = input().split()
r %= n
print(l[r], l[r-1])
