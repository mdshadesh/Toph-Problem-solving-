#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAX = 2e5+10;
int a[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    getline(cin,s);
    s.push_back(' ');
    int n = s.size();
    string ss = "";
    map<string,int>m;
    vector<string>v;
    vector<string>w;
    int mn = 1e9, mx = -1, fr = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ' or s[i] == '.' or s[i] == ',' or s[i] == ';'){
            int z = ss.size();
            v.push_back(ss);
            for(int j = 0; j < z; j++){
                ss[j] = tolower(ss[j]);
            }
            w.push_back(ss);
            m[ss]++;
            mn = min(z,mn);
            mx = max(z,mx);
            fr = max(m[ss],fr);
            ss.clear();
            ss = "";
            if(s[i] != ' ')i++;
        }
        else{
            ss.push_back(s[i]);
        }
    }
    n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i].size() == mx){
            cout << v[i] << '\n';
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i].size() == mn){
            cout << v[i] << '\n';
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(m[w[i]] == fr){
            cout << v[i] << '\n';
            break;
        }
    }

    return 0;
}