#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "3.14159265358979323846264";
    int t, n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<s[n+1]<<endl;
    }

    return 0 ;
}