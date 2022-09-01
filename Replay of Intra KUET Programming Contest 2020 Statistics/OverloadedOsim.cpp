#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105;

int n, x, a[sz], dp[sz][11];
bool vis[sz][11];

int fnc(int i, int m) {
   if(i > n) return 0;
   int &w = dp[i][m];
   bool &done = vis[i][m];
   if(done) return w;
   done = 1, w = INT_MIN;
   int sum = 0, r = n-i+1;
   for(int j=i, k=1; j<=n; j++, k++) {
      sum = (sum + a[j]) % x;
      int now = 0;
      if(k & 1) {
         sum += m;
         sum >= x ? sum -= x : 1;
         now += fnc(j+1, (2*x-sum-m) % x);
      }
      else {
         sum -= m;
         sum < 0 ? sum += x : 1;
         now += fnc(j+1, (sum+m) % x);
      }
      if(r & 1) now += sum;
      w = max(w, now);
   }

   return w;
}

int main() {
   cin >> n >> x;
   ll tot = 0;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), tot += a[i];
   for(int i=1; i<=n; i++) a[i] %= x, a[i] < 0 ? a[i] += x : 1;
   cout << tot + fnc(1, 0) << endl;
}