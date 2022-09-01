#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 105;

typedef pair <ll,ll> pii;
#define x first
#define y second

pii a[sz];

ll cross(pii a, pii b, pii c) {
   return (b.y-a.y) * (c.x-a.x) - (b.x-a.x) * (c.y-a.y);
}

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      cin >> n;
      ll ans = LLONG_MAX;
      for(int i=0; i<n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);
      for(int i=0; i<n; i++) {
         for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
               ll now = abs(cross(a[i], a[j], a[k]));
               if(now) ans = min(ans, now);
            }
         }
      }
      printf("%f\n", (double)ans / 2.0);
   }
}