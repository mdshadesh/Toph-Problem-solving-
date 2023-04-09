import math

for T in range(int(input())):
    X, K = map(int, input().split())
    if K == 0 and X == 1:
        print("=")
    elif K == 0 and X != 1:
        print(">")
    else:
        while K != 1:
            g = math.gcd(X, K)
            if g == 1:
                break
            K //= g
        if K != 1:
            print("<")
        else:
            print("=")
