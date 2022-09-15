#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
int t, n, k, i, a[100005];
int main ()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   #endif
   cin >> t;
   while(t--)
   {
      cin >> n >> k;  vector < pair < int, int > > v;
      for(i = 1; i <= n; i++) cin >> a[i];
      for(i = 1; i < n and k; i++)
      {
         if(a[i] == i and a[i+1] == i+1)
         {
            k--; swap(a[i], a[i+1]);
            v.push_back({i, i+1});
         }
      }
      for(i = 1; i < n and k; i++)
      {
         if(a[i] == i)
         {
            k--; swap(a[i], a[i+1]);
            v.push_back({i, i+1});
         }
      }
      if(k and a[n] == n)
      {
         swap(a[n], a[n-1]);
         v.push_back({n-1, n});
      }
      cout << v.size() << endl;
      for(auto it : v) cout << it.first << ' ' << it.second << endl;
   }
}