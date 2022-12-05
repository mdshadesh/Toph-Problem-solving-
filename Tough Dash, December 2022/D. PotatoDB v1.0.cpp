#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  int cnt = 0;
  map<int, int> mp;
  map<int, int> sum;
  while (q--) {
    char c;
    int x;
    cin >> c >> x;
    x = abs(x);
    if (c == 'A') {
      mp[x] += 1;
      cnt += 1;
      int dig = 0;
      while (x) {
        dig += (x % 10);
        x /= 10;
      }
      sum[dig] += 1;
      cout << cnt << "\n";
    } else if (c == 'D') {
      if (mp[x] > 0) {
        mp[x] -= 1;
        cnt -= 1;
        int dig = 0;
        while (x) {
          dig += x % 10;
          x /= 10;
        }
        sum[dig] -= 1;
      }
      cout << cnt << "\n";
    } else {
      cout << sum[x] << "\n";
    }
  }

  return 0;
}