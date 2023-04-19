def eulers_totient(num):
    res = num
    x = 2
    while x * x <= num:
        if num % x == 0:
            while num % x == 0:
                num //= x
            res -= res // x
        x += 1
    if num > 1:
        res -= res // num
    return res

n = int(input())
if n < 2:
    print(0)
else:
    print(eulers_totient(n))
