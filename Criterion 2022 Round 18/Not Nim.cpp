#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll grundy (ll x) {
  if (x <= 1) return 0;
  int bits = 0;
  while (1LL << (bits + 1) <= x) ++bits;
  x -= (1LL << bits);
  if (!x) return 0;
  int layer = bits - 1;
  while (~x & 1) x >>= 1, --layer;
  return (1LL << layer) + (x >> 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    ll sum = 0;
    while (n--) {
      ll x; scanf("%lld", &x);
      sum ^= grundy(x);
    }
    puts(sum ? "Alice" : "Bob");
  }
  return 0;
}
