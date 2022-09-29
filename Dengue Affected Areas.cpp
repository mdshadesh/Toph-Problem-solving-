#include<bits/stdc++.h>
using namespace std;
#define N 100005
int ar[N], a, b;
vector<int> v[N*4];
struct que
{
  int c, mn, mx;
  que(int a, int b, int cd){
    c = a, mn = b, mx = cd;
  }
};
void build(int at, int l, int r)
{
  if (l == r){
    v[at].push_back(ar[l]);
    return;
  }
  int m = (l+r) >> 1;
  build(at << 1, l, m); build(at << 1 | 1, m+1, r);
  merge(v[at << 1].begin(), v[at << 1].end(), v[at << 1 | 1].begin(), v[at << 1 | 1].end(), back_inserter(v[at]));
}
que add(que a, que b){return que(a.c+b.c, min(a.mn, b.mn), max(a.mx, b.mx));}
que querry(int at, int l, int r, int ql, int qr)
{
  if (ql > r || qr < l) return que(0, 1000000001, 0);
  if (ql <= l && qr >= r){
    int u = lower_bound(v[at].begin(), v[at].end(), a)-v[at].begin();
    int vu = upper_bound(v[at].begin(), v[at].end(), b)-v[at].begin();
    if (u < vu) return que(vu-u, v[at][u], v[at][vu-1]);
    else return que(0, 1000000001, 0);
  }
  int m = (l+r) >> 1;
  que g = querry(at << 1, l, m, ql, qr);
  que h = querry(at << 1 | 1, m+1, r, ql, qr);
  return add(g, h);
}
int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  build(1, 1, n);
  while(m--){
    int l, r;
    scanf("%d %d %d %d", &l, &r, &a, &b);
    que res = querry(1, 1, n, l, r);
    if (res. c == 0) res = que(0, -1, -1);
    printf("%d %d %d\n", res.c, res.mn, res.mx);
  }
  return 0;
}