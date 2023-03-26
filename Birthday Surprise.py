import math

def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

n = int(input())
a = list(map(int, input().split()))

pf = [0] * (n+1)
for i in range(1, n+1):
    pf[i] = pf[i-1] + a[i-1]

q = int(input())
cnt = 0
for _ in range(q):
    l, r = map(int, input().split())
    if isPrime(pf[r] - pf[l-1]):
        cnt += 1

if cnt == 0:
    print("Adnan bhai, Priyom dada, Shuvo bhai will forever be single!")
elif cnt == 1:
    print("Sokina Khatun will be very happy!")
elif cnt == 2:
    print("Sokina Khatun will be very very happy!")
else:
    print("Sokina Khatun will be very very very happy!")
