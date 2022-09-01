#include<bits/stdc++.h>

using namespace std;

struct node {
  int to, cost;
  bool operator < (const node &var) const &{
    return var.cost < cost;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, C, K;
  cin >> n >> m >> C >> K;
  vector<vector<pair<int, pair<int, int>>>> g(n);
  for (int i = 0; i < m; i++){
    int u, v, c, k;
    cin >> u >> v >> c >> k;
    u--; v--;
    g[u].push_back({v, {c, k}});
    g[v].push_back({u, {c, k}});
  }
  const int inf = 1e9 + 5;
  auto path = [&] (int M) {
    vector<int> cost(n, inf);
    vector<bool> taken(n, false);
    priority_queue<node> pq;
    pq.push({0, 0});
    cost[0] = 0;
    while (!pq.empty()){
      auto u = pq.top();
      pq.pop();
      if (taken[u.to]){
        continue;
      }
      taken[u.to] = true;
      for (auto v : g[u.to]){
        if (v.second.second >= M && cost[v.first] > cost[u.to] + v.second.first) {
          cost[v.first] = cost[u.to] + v.second.first;
          pq.push({v.first, cost[v.first]});
        }
      }
    }
    return cost[n - 1];
  };
  int lo = 1;
  int hi = K;
  int ans = 0;
  while (lo <= hi){
    int mid = (lo + hi) >> 1;
    if (path(mid) <= C){
      ans = max(ans, mid);
      lo = mid + 1;
    } else {
      hi = mid - 1;    
    }
  }
  cout << ans << "\n";
  return 0;
}