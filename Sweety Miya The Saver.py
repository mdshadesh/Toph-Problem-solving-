

MAXN = 10000
sieve = [True] * MAXN
for p in range(2, 1000):
    if sieve[p]:
        for i in range(p*p, MAXN, p):
            sieve[i] = False

for t in range(int(input())):
    n, s = input().split()
    n = int(n)
    ans = -1
    for i in range(n):
        for j in range(i, min(i+4, n)):
            tmp = int(s[i:j+1])
            if sieve[tmp]:
                ans = max(ans, tmp)
    print('Case {}: {}'.format(t+1, ans if ans != -1 else 'This is a junk!'))

