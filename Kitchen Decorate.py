import math

T = int(input())

for _ in range(T):
    W, H = map(int, input().split())
    gcd = math.gcd(W, H)
    max_height = gcd
    print(max_height)
