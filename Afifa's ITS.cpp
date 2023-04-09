#include <bits/stdc++.h>

using namespace std;

#define ll long long

priority_queue<ll> q;

ll c[100010];
vector<ll> g[100010];

int main()
{
    ll i, j, k, l, ans = 0, n, u, v;

    cin >> n;

    for (i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        c[u]++;
        c[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
        if (c[i] == 1)
            q.push(-i);

    i = 1;
    while (q.size())
    {
        ll x = q.top();
        q.pop();
        ans = max(ans, -x * (n - i));
        c[-x]--;
        for (j = 0; j < g[-x].size(); j++)
        {
            ll adj = g[-x][j];
            c[adj]--;
            if (c[adj] == 1 || (c[adj] > 1 && c[adj] == g[adj].size() - 1))
                q.push(-adj);
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}
