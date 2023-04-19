import math

for _ in range(int(input())):
    n, a, b, mod = map(int, input().split())
    p = n // a
    j = ((p * (p + 1) // 2) * a) % mod
    q = n // b
    k = ((q * (q + 1) // 2) * b) % mod
    r1 = a * b // math.gcd(a, b)
    r = n // r1
    l = ((r * (r + 1) // 2) * r1) % mod
    print((j + k - l) % mod)
