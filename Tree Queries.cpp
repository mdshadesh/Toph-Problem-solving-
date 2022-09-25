#include<bits/stdc++.h>
using namespace std;

#define N 500005
vector<int> ad[N], tree[N];
int val[N];

void dfs(int s, int par)
{
  tree[s].push_back(val[s]);
  for (int a: ad[s])
  {
    if (a == par) continue;
    dfs(a, s);
    tree[s].insert(tree[s].end(), tree[a].begin(), tree[a].end());
  }
  sort(tree[s].begin(), tree[s].end());
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 2; i <= n; i++)
  {
    int a;
    scanf("%d", &a);
    ad[a].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  dfs(1, -1);
  while(m--)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    int i = lower_bound(tree[a].begin(), tree[a].end(), b)-tree[a].begin();
    cout << tree[a].size() - i << endl;
  }
}