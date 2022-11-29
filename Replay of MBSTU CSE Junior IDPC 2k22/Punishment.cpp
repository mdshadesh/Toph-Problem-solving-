#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << #a << ": " << a << "\n"

using ll = long long;

void solve() {
  int n, m;  cin >> n >> m;
  vector<int> p(n);
  for (auto &pi: p) {
    cin >> pi;
  }
  int done = 0;
  for (auto pi: p) {
    if (done + 1 == pi) {
      done++;
    }
  }

  if (done > m and (n - done) > m) {
    cout << "No\n";
    return ;
  }

  for (auto pi: p) {
    if (done + 1 == pi) {
      done++;
    }
  }

  if (done == n) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int tc;  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}