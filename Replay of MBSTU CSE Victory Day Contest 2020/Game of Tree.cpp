#include <bits/stdc++.h>
using namespace std;
const int M = 100001;
int t, n, k, c[M], mx, i, a, b, kase; vector < int > g[M];
void dfs(int x, int p)
{
   c[x] = 1;
   for(auto it : g[x])
   {
      if(it != p)
      {
         dfs(it, x);
         c[x] += c[it];
      }
   }
}

int main ()
{
   scanf("%d", &t);
   while(t--)
   {
      scanf("%d %d", &n, &k); mx = 0;
      for(i = 1; i < n; i++)
      {
         scanf("%d %d", &a, &b);
         g[a].emplace_back(b);
         g[b].emplace_back(a);
      }
      dfs(k, 0);
      for(int it : g[k]) mx = max(mx, c[it]);
      printf("Case %d: %s\n", ++kase, mx + mx > n ? "Yes" : "No");
      for(i = 1; i <= n; i++) g[i].clear(), c[i] = 0;
   }
}