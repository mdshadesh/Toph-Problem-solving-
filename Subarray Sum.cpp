#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];
int dp[N][N];

int main()
{
    int tt, t;
    int n, k;
    int i, j;
    int ans;

    scanf("%d", &tt);
    for(t = 1; t <= tt; t ++)
    {
        scanf("%d%d", &n, &k);
        for(i = 1; i <= n; i ++)
            scanf("%d", &a[i]);

        for(i = 1, ans = -1e6; i <= n; i ++)
        {
            dp[i][0] = max(dp[i - 1][0], 0) + a[i];
            for(j = 1; j <= k && j <= i; j ++)
                dp[i][j] = max({dp[i - 1][j] + a[i], dp[i - 1][j - 1], a[i]});
            for(j = 0; j <= k && j <= i; j ++)
                ans = max(ans, dp[i][j]);
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}