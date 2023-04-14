from math import radians, sin, cos

for _ in range(int(input())):
    r, x = map(int, input().split())
    x = radians(x)
    print(r * sin(x) / (sin(x) ** 2 + cos(x)))
