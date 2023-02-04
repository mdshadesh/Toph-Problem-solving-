#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 998244353
 
int ar[mx];
ll dist[mx];
vector<pair<int,int>>g[mx];
int dp[mx][101];
int vis[mx][101];
int n,m,ii,k;
int s,t;

int add(int a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}
int mul(int a,int b)
{
    ll re=a;
    re*=b;
    if(re>=mod)re%=mod;
    return re;
}

int func(int u,int dif){
    if(vis[u][dif]==ii)return dp[u][dif];
    vis[u][dif]=ii;
    int re=(u==t);
    for(auto[v,w]:g[u]){
        ll extra=dist[u]+w+dif-dist[v];
        if(extra<=k){
            re=add(re,func(v,extra));
        }
    }
    return dp[u][dif]=re;

}
 
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    
    scanf("%d%d",&s,&t);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    priority_queue<pair<ll,int>>pq;
    for(int i=1;i<=n;i++)dist[i]=1e18;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto[cost,u]=pq.top();
        cost*=-1;
        pq.pop();
        if(dist[u]<cost)continue;
        for(auto[v,w]:g[u]){
            if(dist[v]>cost+w){
                dist[v]=cost+w;
                pq.push({-dist[v],v});
            }
        }
    }
    ii++;
    printf("%d\n",func(s,0));
    for(int i=1;i<=n;i++)g[i].clear();


 
}
 
int main()
{
    int tt=1;
    scanf("%d",&tt);
    while(tt--)solve();
    return 0;
}