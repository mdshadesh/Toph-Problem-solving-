MAX = 1000
weight = [0] * MAX
cost = [0] * MAX

tcase = int(input())
for kase in range(1, tcase+1):
    n, cap = map(int, input().split())
    for i in range(n):
        weight[i], cost[i] = map(int, input().split())
    ans = [0] * (cap+5)
    for j in range(n):
        for i in range(cap, weight[j]-1, -1):
            ans[i] = max(ans[i], cost[j] + ans[i-weight[j]])
    print(ans[cap])
