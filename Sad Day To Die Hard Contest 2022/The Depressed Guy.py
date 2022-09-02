n = int(input())
nl = list(map(int, input().split()))
d = {}
ans = 1
for i in range(n):
	if nl[i] not in d:
		d[nl[i]]=i
	x = i-d[nl[i]]+1
	if x > ans:
		ans = x
print(ans)