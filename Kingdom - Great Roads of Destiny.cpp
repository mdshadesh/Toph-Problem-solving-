#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e6+6;
vector<int> g[N];
int low[N], depth[N], vis[N], e, h, cur_ans[N], par[N][21];
void dfs(int u, int p, int d)
{
    vis[u] = 1;
    depth[u] = low[u] = d;
    par[u][0] = p;
    for(int v: g[u])
    {
        if(v == p) continue;
        else if(vis[v] == 0)
        {
            dfs(v, u, d+1);
            low[u] = min(low[u], low[v]);
        }
        else if(depth[v] < depth[u]) low[u] = min(low[u], depth[v]);
    }
}
void dfs2(int u, int p, int d)
{
    vis[u] = 0;
    if(low[u] >= depth[u]) d++;
    cur_ans[u] = d;
    for(int v: g[u])
    {
        if(vis[v] == 1) dfs2(v, u, d);
    }
}
int kth_parent(int u, int k)
{
    for(int b = 20; b>=0; b--)
    {
        if((k>>b)&1) u = par[u][b];
    }
    return u;
}
int LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int dif = depth[u]-depth[v];
    u = kth_parent(u, dif);
    if(u == v) return u;
    else
    {
        for(int k=20; k>=0; k--)
        {
            if(par[u][k] != par[v][k] and par[u][k] != -1) u = par[u][k], v = par[v][k];
        }
        return par[v][0];
    }
}
int32_t main()
{
    int t, n, m, x, y, q;
    cin >> t;
    for(int cas = 1; cas <= t; cas++)
    {
        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
            cin >> x >> y;
            g[x].pb(y), g[y].pb(x);
        }
        dfs(1, -1, 0), dfs2(1, -1, 0);
        for(int k=1; k<=20; k++)
        {
            for(int u=1; u<=n; u++)
            {
                if(par[u][k-1] == -1) par[u][k] = -1;
                else par[u][k] = par[par[u][k-1]][k-1];
            }
        }
        cin >> q;
        cout << "Case " << cas << ":\n";
        for(int i=0; i<q; i++)
        {
            cin >> e >> h;
            cout << cur_ans[e]+cur_ans[h]-2*cur_ans[LCA(e, h)] << '\n';
        }
        for(int i=1; i<=n; i++) g[i].clear();
    }
}