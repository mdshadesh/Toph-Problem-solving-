#include <bits/stdc++.h>
using namespace std;

const int K = 52;
const int N = 10005;
int n, k, p[N], dp[N][K], sf[N];

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string line;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  getline(cin, line);
  for (int i = n; i >= 1; --i) sf[i] = sf[i + 1] + p[i];
  for (int i = n; i >= 1; --i) 
  {
    for (int j = k; j >= 0; --j) 
    {
      dp[i][j] = sf[i] - dp[i + 1][0];
      if (j < k) dp[i][j] = max(dp[i][j], sf[i] - dp[i][j + 1]);
    }
  }
  if (dp[1][0] >= sf[1] - dp[1][0]) 
  {
    cout << "first" << endl;
    int i = 1, j = 0;
    while (i <= n) 
    {
      if (dp[i][j] == sf[i] - dp[i + 1][0]) 
      {
        cout << "purchase" << endl;
        ++i, j = 0;
        getline(cin, line);
      } else 
      {
        cout << "skip" << endl;
        ++j;
      }
      if (i > n) break;
      string res; cin >> res;
      getline(cin, line);
      if (res[0] == 's') ++j;
      else ++i, j = 0, getline(cin, line);
    }
  } 
  else 
  {
    cout << "second" << endl;
    int i = 1, j = 0;
    while (i <= n) 
    {
      string res; cin >> res;
      getline(cin, line);
      if (res[0] == 's') ++j;
      else ++i, j = 0, getline(cin, line);
      if (i > n) break;
      if (dp[i][j] == sf[i] - dp[i + 1][0]) 
      {
        cout << "purchase" << endl;
        ++i, j = 0;
        getline(cin, line);
      } 
      else 
      {
        cout << "skip" << endl;
        ++j;
      }
    }
  }
  return 0;
}
