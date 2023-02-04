#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

const static int MAX = 10010;
int n, m, k, cs = 1;
int A[MAX], B[MAX];
long long cache[MAX][11][11][11];
int vis[MAX][11][11][11];

long long find_max_score_rec(int posA, int posB, int taken, int dropped)
{
    if (posA == n + 1 && posB == m)
    {
        return 0;
    }
    if(vis[posA][posB][taken][dropped] == cs) return cache[posA][posB][taken][dropped];
    vis[posA][posB][taken][dropped] = cs;

    long long ans = LLONG_MIN;
    if (posA <= n)
    {
        ans = std::max(ans, find_max_score_rec(posA + 1, posB, taken, dropped) + (1LL * A[posA] * (posA + taken - dropped)));
        if (dropped < k)
        {
            ans = std::max(ans, find_max_score_rec(posA + 1, posB, taken, dropped + 1));
        }
    }
    if (posB < m)
    {
        ans = std::max(ans, find_max_score_rec(posA, posB + 1, taken + 1, dropped) + (1LL * B[posB] * (posA + taken - dropped)));
        ans = std::max(ans, find_max_score_rec(posA, posB + 1, taken, dropped));
    }
    return cache[posA][posB][taken][dropped] = ans;
}

long long find_max_score()
{
    std::sort(B, B + m);
    for (int i = 1; i <= n; i *= 2) {
        find_max_score_rec(i, 0, 0, 0);
    }
    auto res = find_max_score_rec(1, 0, 0, 0);
    ++cs;
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &B[i]);
        }
        printf("%lld\n", find_max_score());
    }
    return 0;
}