x, y = map(int, input().split())
tlist = []
ans = 0
for i in range(x):
	t = input()
	tlist.append(t)
	if "=" not in t:
		continue
	for j in range(len(t)):
		if t[j] == "=":
			for k in tlist:
				if k[j] == "O":
					ans += 1
print(ans)

