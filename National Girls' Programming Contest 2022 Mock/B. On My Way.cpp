#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<pair<int,ll>>> g;
vector<ll> dis;
ll dp[200005][105];
int k;
int s,e;
ll big=998244353;

void diks(){
    dis[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,s});
    while(q.size()){
        pair<ll,int> xx=q.top();
        q.pop();
        int u=xx.second;
        ll d=xx.first;
        if(d>dis[u]) continue;
        for(auto it:g[u]){
            int v=it.first;
            ll w=it.second;
            if(dis[v]>d+w){
                dis[v]=d+w;
                q.push({dis[v],v});
            }
        }
    }
}   

ll f(int i, int dev){
    if(dev>k) return 0;
    if(dp[i][dev]!=-1) return dp[i][dev];
    ll ret=0;
    if(i==e) ret++;
    for(auto it:g[i]){
        ll nd=dis[i]+it.second+dev;
        ret=(ret+f(it.first,nd-dis[it.first]))%big;
    }
    dp[i][dev]=ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m>>k;

        g.assign(n+1,{});
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        dis.assign(n+1,1e15);

        cin>>s>>e;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        diks();

        ll ans=f(s,0);

        cout<<ans<<"\n";
    }


}