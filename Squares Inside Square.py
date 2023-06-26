t = int(input())

for _ in range(t):
    n = int(input())
    squares = (n * (n + 1) * (2 * n + 1)) // 6
    print(squares)
