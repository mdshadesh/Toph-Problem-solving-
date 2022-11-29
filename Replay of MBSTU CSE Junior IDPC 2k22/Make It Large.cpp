#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k;
  cin >> n >> m;
  string S, T;
  cin >> S >> T;
  if (m == 1) {
    for (i = n - 1; i >= 0; i--) {
      if (S[i] == T[0]) {
        cout << i + 1 << endl;
        return 0;
      }
    }
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  for (i = 0; i < n; i++) {
    if (S[i] == T[0]) {
      ans.push_back(i + 1);
      break;
    }
  }
  for (j = n - 1; j > i; j--) {
    if (S[j] == T[m - 1]) {
      ans.push_back(j + 1);
      break;
    }
  }
  int ind = m - 2;
  for (k = j - 1; k > i && ind; k--) {
    if (S[k] == T[ind]) {
      ans.push_back(k + 1);
      ind -= 1;
    }
  } 
  int sz = ans.size();
  if (sz < m) {
    cout << -1 << endl;
  } else {
    sort(ans.begin(), ans.end());
    for (i = 0; i < m; i++) {
      cout << ans[i] << " \n"[i == m - 1];
    }
  }
  return 0;
}