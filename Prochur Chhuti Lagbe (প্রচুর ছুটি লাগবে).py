n = int(input())
arr = [0] * 10005

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x-1, y):
        arr[i] += 1

q = int(input())
sm = 0

for _ in range(q):
    a, b = map(int, input().split())
    f = False
    for i in range(a-1, b):
        if arr[i] != 0:
            f = True
            break
    if not f:
        arr[a-1:b] = [1] * (b-a+1)
        sm += (b-a+1)

print(sm)
