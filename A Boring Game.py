for tc in range(1, int(input().strip()) + 1):
    n = int(input().strip())

    deg = [0] * n
    for i in range(n-1):
        u, v = map(int, input().strip().split())
        u -= 1
        v -= 1
        deg[u] += 1
        deg[v] += 1

    res = sum(1 for d in deg if d != n-1)
    print("Case {}: {}".format(tc, res))
