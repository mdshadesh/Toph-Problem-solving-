#include <stdio.h>

#define int_max 2147483647
#define min(a, b) (a < b ? a : b);

int solve(int n, int m)
{
    if (m < 1)
        return 0;

    int p = 1, k = 0;
    int ans = int_max;

    while (p < n)
    {
        int d = (p + n) >> 1;
        k++;
        int l = d + d - 2;

        if (m <= d - 1)
        {
            ans = min(ans, k);
        }
        else if (m <= l)
        {
            ans = min(ans, k + 1);
        }
        else
        {
            int x = m / l;
            int y = x * (k + 1);
            ans = min(ans, y + solve(n, m - x * l));
        }

        if (p < d)
        {
            p = d;
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        int n, m, ans = -1;

        scanf("%d %d", &n, &m);

        if (n > 2)
            ans = solve(n, m);

        printf("%d\n", ans);
    }

    return 0;
}