import math

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n+1, 2):
        if n % i == 0:
            return False
    return True

T = int(input())

for _ in range(T):
    N = int(input())
    largest_prime_smaller = None
    smallest_prime_larger = None
    for i in range(N-1, 1, -1):
        if is_prime(i):
            largest_prime_smaller = i
            break
    for i in range(N+1, N+500):
        if is_prime(i):
            smallest_prime_larger = i
            break
    print(largest_prime_smaller, smallest_prime_larger)
