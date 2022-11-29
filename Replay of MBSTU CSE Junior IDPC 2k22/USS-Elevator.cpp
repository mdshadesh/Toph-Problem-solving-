#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << #a << ": " << a << "\n"

using ll = long long;

void solve() {
  int n;  cin >> n;
  vector<ll> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  ll x, y;  cin >> x >> y;
  int in = 0;
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    int mn = min(a[i - 1], a[i]);
    int mx = max(a[i - 1], a[i]);
    if (!in and mn <= x and x <= mx) {
      in = 1;
      ans += abs(x - a[i - 1]);
      a[i - 1] = x;
    }

    mn = min(a[i - 1], a[i]);
    mx = max(a[i - 1], a[i]);

    if (in and mn <= y and y <= mx) {
      ans += abs(y - a[i - 1]);
      cout << "YES\n";
      cout << ans << "\n";
      return ;
    }
    ans += mx - mn;
  }

  cout << "NO\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc = 1;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}