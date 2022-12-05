#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, i, j, k;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n, 0);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      for (k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (a[i] * a[i] + a[j] * a[j] == a[k] * a[k]) {
          b[i] = b[j] = b[k] = 1;
        }
      }
    }
  }
  cout << count(b.begin(), b.end(), 1) << endl;
  return 0;
}