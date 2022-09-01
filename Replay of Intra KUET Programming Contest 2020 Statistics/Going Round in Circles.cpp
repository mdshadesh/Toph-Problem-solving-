#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];
ll bit[sz];

void add(int x, int n, int v) {
   while(x <= n) {
      bit[x] += v;
      x += x & (-x);
   }
}

ll quer(int x) {
   ll ans = 0;
   while(x) {
      ans += bit[x];
      x -= x & (-x);
   }
   return ans;
}

bool fnc(int x) {
   if(!x) return 1;
   int y = 32 - __builtin_clz(x);
   return x + 1 == 1 << y;
}

int main() {
   int n, q;
   cin >> n >> q;
   set <int> st;
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      add(i, n, a[i]);
      if(fnc(a[i])) continue;
      st.emplace(i);
   }

   while(q--) {
      int t, l, r;
      scanf("%d %d %d", &t, &l, &r);
      if(t == 1) {
         auto it = st.lower_bound(l);
         vector <int> bad;
         while(it != st.end()) {
            int x = *it;
            if(x > r) break;
            int v = a[x];
            int y = 31 - __builtin_clz(v);
            v ^= 1 << y;
            v <<= 1;
            v |= 1;
            add(x, n, v - a[x]);
            a[x] = v;
            if(fnc(v)) bad.push_back(x);
            it++;
         }
         for(int x : bad) st.erase(x);
      }
      else printf("%lld\n", quer(r) - quer(l-1));
   }
}