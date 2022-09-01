#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

typedef pair <int, bool> pii;
#define x first
#define y second

int a[sz], spf[sz], cnt[sz];

void sive() 
{
   for(int i=2; i<sz; i++) 
   {
      if(spf[i]) continue;
      for(int j=i; j<sz; j+=i) if(!spf[j]) spf[j] = i;
   }
}

vector <pii> factor(int x) 
{
   vector <pii> pf;
   while(x > 1) 
   {
      int y = spf[x];
      while(x % y == 0) x /= y;
      for(auto &p : pf) 
      {
         if(p.x > sz / y) continue;
         int z = p.x * y;
         if(z < sz) pf.emplace_back(z, p.y ^ 1);
      }
      pf.emplace_back(y, 1);
   }
   return pf;
}

int got(vector <pii> &pf) 
{
   int res = 0;
   for(auto &p : pf) 
   {
      if(p.y) res += cnt[p.x];
      else res -= cnt[p.x];
   }
   return res;
}

int main() 
{
   sive();
   int n;
   cin >> n;
   for(int i=0; i<n; i++) 
       scanf("%d", &a[i]);
   sort(a, a+n);
   n = unique(a, a+n) - a;
   reverse(a, a+n);

   ll ans = 0;
   if(a[n-1] == 1) 
   {
      ans = a[0];
      n--;
   }
   stack <int> st;
   for(int i=0; i<n; i++) 
   {
      auto pf = factor(a[i]);
      int cop = got(pf);
      while(cop < st.size()) 
      {
         int bad = st.top(); st.pop();
         auto pfb = factor(bad);
         for(auto &p : pfb) cnt[p.x]--;
         cop = got(pf);
         if(cop == st.size()) 
         {
            ans = max(ans, 1LL * a[i] * bad);
            break;
         }
      }
      st.push(a[i]);
      for(auto &p : pf) cnt[p.x]++;
   }
   if(ans) cout << ans << endl;
   else puts("-1");
}