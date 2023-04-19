import sys

n = int(input().strip())

# Reading the graph
g = [list(map(int, input().strip().split())) for _ in range(n)]

q = int(input().strip())
for _ in range(q):
    u, v = map(int, input().strip().split())
    mi = g[u][v]
    for w in range(n):
        mi = min(mi, g[u][w] + g[w][v])
    print(mi)
