n, m = map(int, input().split())

outerPoly = []
innerPoly = []

for i in range(n):
    x, y = map(int, input().split())
    x *= 2
    y *= 2
    outerPoly.append((x, y))

for i in range(m):
    x, y = map(int, input().split())
    x *= 2
    y *= 2
    innerPoly.append((x, y))

cand = []
for P in outerPoly:
    for Q in innerPoly:
        cand.append(((P[0] + Q[0]) // 2, (P[1] + Q[1]) // 2))

def area(A, B, C):
    return A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - A[1] * B[0] - B[1] * C[0] - C[1] * A[0]

def convexHull(p):
    n = len(p)
    if n < 3: return p
    p = sorted(p)
    hull = []
    for i in range(n):
        while len(hull) >= 2 and area(hull[-2], hull[-1], p[i]) <= 0:
            hull.pop()
        hull.append(p[i])
    for i in range(n - 2, -1, -1):
        while len(hull) >= 2 and area(hull[-2], hull[-1], p[i]) <= 0:
            hull.pop()
        hull.append(p[i])
    return hull[:-1]

hull = convexHull(cand)

print(len(hull))
for P in hull:
    print(str(P[0] // 2) + ('.5' if P[0] % 2 else '') + ' ' + str(P[1] // 2) + ('.5' if P[1] % 2 else ''))
