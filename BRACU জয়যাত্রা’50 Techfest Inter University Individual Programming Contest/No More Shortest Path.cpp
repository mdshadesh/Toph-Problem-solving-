#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1000 +5;
const ll mod = 1e9+7;
typedef pair<int,int> pii;

vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;
int weight[N][N];
int n,m,src;
bool vis[N];
bool vis2[N];
void dfs(int s)
{
    vis[s] = 1;
    for(int i:g[s])
    {
        if(!vis[i])
            dfs(i);
    }
}
void ddfs(int s)
{
    vis2[s] = 1;
    for(int i:g[s])
    {
        if(!vis2[i])
            ddfs(i);
    }
}
void dfs1 (int v)
{
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v)
{
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
vector<ll>dist[N];
void dijkstra(int s, vector<ll>&dist)
{
    dist.resize(n,1e18);
    vector<bool>visited(n,false);
    priority_queue <pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        ll a = pq.top().second;
        pq.pop();
        if (visited[a])
            continue;
        visited[a] = true;
        for (int i : g[a])
        {
            if(dist[i]> dist[a]+ weight[a][i])
            {
                dist[i]= dist[a]+ weight[a][i];
                pq.push({dist[i],i});
            }
        }
    }
}
void scc()
{
    order.clear();
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    ll x1 =0, x2 = 0;
    for (int i=0; i<n; ++i)
    {
        int v = order[n-1-i];
        if (!used[v])
        {
            component.clear();
            dfs2 (v);
            reverse(component.begin(),component.end());
            if(component.size()==1 || vis[component[0]]==0 || vis2[component[0]])
                continue;
            ll now = 1e18;
            for(int i=0; i<component.size(); i++)
            {
                for(int j=0; j<component.size(); j++)
                {
                    if(i==j)
                        continue;
                    int u = component[i];
                    int v = component[j];
                    now = min(now, dist[u][v] + dist[v][u]);
                }
            }
            for(int i=0; i<component.size(); i++)
            {
                if(!vis2[component[i]])
                    ddfs(component[i]);
            }
            debug(component,now);
            x2 += now;
            x2++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(vis2[i])
            x1++;
    }
    cout<<x1<<" "<<x2<<"\n";
}
void TEST_CASES(int cas)
{

    g.clear();
    gr.clear();
    memset(vis,0,sizeof vis);
    memset(vis2,0,sizeof vis2);
    cin>>n>>m>>src;
    src--;
    g.resize(n);
    gr.resize(n);
    for(int i=0; i<n; i++)
    {
        dist[i].clear();
        for(int j=0; j<n; j++)
        {
            weight[i][j] = 2e9;
        }
    }
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        g[u].push_back(v);
        gr[v].push_back(u);
        weight[u][v] = min(weight[u][v], w);
    }
    for(int i=0; i<n; i++)
    {
        dijkstra(i,dist[i]);
    }
    dfs(src);
    scc();
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t=1,cas=0;
    cin>>t;
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}