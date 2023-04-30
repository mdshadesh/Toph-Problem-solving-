t = int(input())
for _ in range(t):
    n, h = map(int, input().split())
    ai = list(map(int, input().split()))
    bi = list(map(int, input().split()))
    vpr = list(zip(ai, bi))
    vpr.sort()
    y, kc = 0, 0
    while h >= 0 and y < n:
        h -= vpr[y][0]
        if h < 0:
            break
        kc += 1
        h += vpr[y][1]
        y += 1
    print(kc)
