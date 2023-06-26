import math
for _ in range(int(input())):
    x, y = map(float, input().split())
    print((x * x + y * y) * ((y / x) - math.atan(y / x)))
