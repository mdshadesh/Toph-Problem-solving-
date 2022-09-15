#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
int n, i, j, cnt; string s;
int main ()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   #endif
   cin >> n;
   for(i = 1; i <= n; i++)
   {
      bool pos = false;
      s = to_string(i);
      for(j = 0; j < s.size(); j++) if(s[j] == '1') pos = true;
      cnt += pos == true;
   }
   cout << cnt << endl;
}