#include <bits/stdc++.h>
using namespace std;

bool checkFrom(const string& s, int i) {
   int st = 0;
   for(int j = 0; j < (int)s.size(); j++) {
      int ii = (i + j) % s.size();
      //cerr << "ii = " << ii << "\n";
      if(s[ii] == '(') st++;
      else st--;
      if(st < 0) return false;
   }
   return st == 0;
}
bool is_proper(const string& s) {
   for(int i = 0; i < (int)s.size(); i++) {
      if(s[i] == '(') {
         return checkFrom(s, i);
      }
   }
   return false;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);string s;cin >> s;
   if(count(s.begin(), s.end(), '(') == s.size()) {
      cout << "-1\n";exit(0);
   }
   int mx = 0, mxi = -1;
   for(int i = 0; i < (int)s.size(); i++) {
      int cc = 0;bool done = false;int j;int st = 0;
      if(s[i] == '(') {
         st++;
         cc++;
      }
      for(j = i+1; st > 0;) {
         if(cc >= (int)s.size()) {
            done = true;break;
         }
         if(s[j] == '(') {
            st++;cc++;
         } else st--;
         j++;
         if(j >= (int)s.size()) done = true;
         j %= s.size();
      }
      if(cc > mx) {
         mx = cc; mxi = i;
      }
      i = j-1;
      if(done) break;
   }
   if(mxi == -1 or not checkFrom(s, mxi)) {
      cout << "-1\n";
      exit(0);
   }
   rotate(s.begin(), s.begin()+mxi, s.end());
   cout << s << "\n";
}