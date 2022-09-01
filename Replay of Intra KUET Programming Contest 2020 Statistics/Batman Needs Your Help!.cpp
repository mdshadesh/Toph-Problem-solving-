#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

string a, b;
int mncr[sz<<1];

string manacher(const string str) {
   string s;
   s += '#';
   for(char x : str) s += x, s += '#';

   int w = 0;
   mncr[0] = 1;
   int n = s.size();
   for(int i=1, c=0, r=0; i<n; i++) {
      int now = i > r ? 1 : min(mncr[(c<<1) - i], r - i);
      while(0 <= i-now && i+now < n && s[i+now] == s[i-now]) now++;
      if(i+now-1 > r) r = i+now-1, c = i;
      mncr[i] = now;
      if(now > i) w = i+now-1;
   }

   string res;
   for(int i=1; i<=w; i++) if(s[i] != '#') res += s[i];
   return res;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> a >> b;
   int na = a.size(), nb = b.size();
   reverse(b.begin(), b.end());

   int p = 0;
   for(int i=0; i<min(na, nb); i++) {
      if(a[i] ^ b[i]) break;
      p = i+1;
   }

   string exa = manacher(a.substr(p, na - p));
   string exb = manacher(b.substr(p, nb - p));

   cout << a.substr(0, p);
   if(exa.size() > exb.size()) cout << exa;
   else if(exb.size() > exa.size()) cout << exb;
   else if(exa < exb) cout << exa;
   else cout << exb;
   reverse(b.begin(), b.end());
   cout << b.substr(nb - p, nb) << endl;
}