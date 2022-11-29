#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << #a << ": " << a << "\n"

using ll = long long;

void solve() {
  ll l, r;  cin >> l >> r;
  ll tot = r - l + 1;

  if (l == 0) {
    if (r == 0 or tot % 4 == 0) {
      cout << "0\n";
    }
    else {
      cout << "-1\n";
    }
  }
  else {
    if (tot % 4 == 0) {
      cout << (l & 1) << "\n";
    }
    else if (tot % 4 == 3) {
      cout << (l - 1) << "\n";
    }
    else if (r == l) {
      cout << l << "\n";
    }
    else {
      cout << "-1\n";
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}