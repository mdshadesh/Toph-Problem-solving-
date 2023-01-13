#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            ans++;
            s[i] = '1';
            if(i+1 < n) s[i+1] = '1';
        }
    }
    cout<< ans << '\n';
}