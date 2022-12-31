def main():
	n,k = map(int, input().split())
	build = list(map(int, input().split()))

	lo = 0
	hi = max(build) + k

	while lo <= hi:
		mid = (lo + hi)//2
		require = sum([(mid-h) for h in build if h <= mid])
		if require <= k:
			lo = mid + 1
		else:
			hi = mid - 1
	print(lo-1)
if __name__ == '__main__':
	main()
