

for t in range(int(input())):
	input()
	S=list(map(int,input().split()))
	if S.count(S[0]) == len(S):
		print("neutral")
	elif S == sorted(S):
		print("allGoodDays")
	elif S == sorted(S, reverse=True):
		print("allBadDays")
	else:
		pi =- 1
		mi =- 1
		for i in range(1,len(S)-1):
			if S[i-1]<S[i] and S[i]>S[i+1]:
				if pi is -1:
					pi = i
				else:
					mi=max(mi, i - pi + 1 - 2);
					pi=i
		if mi ==- 1:
			print("none")
		else:
			print(mi)


