#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, i, mx, a[100005], dp[100005];
int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++) 
       cin >> a[i];
   for(i = n; i; i--)
   {
      dp[i] = max(dp[i+1], mx - a[i]);
      mx = max(mx, a[i] + dp[i+2]);
   }
   cout << dp[1] << endl;
}