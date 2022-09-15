#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int n, a[sz], bit[sz], big[sz];

void add(int x, int v) {
   while(x <= n) {
      bit[x] += v;
      x += x & -x;
   }
}

int quer(int x) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   ll ans = 0;
   for(int i=1; i<=n; i++) {
      ll c = quer(a[i]);
      big[i] = quer(a[i] - 1);
      ans += c * (c - 1) / 2;
      add(a[i], 1);
   }
   memset(bit, 0, sizeof bit);
   for(int i=n; i; i--) {
      ll c = n - i - quer(a[i] - 1);
      ans -= c * big[i];
      add(a[i], 1);
   }
   cout << ans;
}