// Naimul Hasan Shadesh
// SOnargaon University

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,a,b;
    cin>>n>>a;
    int x;
    set<int> d;
    for(int i=1;i<=n+a;i++)
    {
        cin>>x;
        d.insert(x);
    }
    set<int>::iterator ok;
    ok=d.begin();
    int i=0;
    while(ok!=d.end())
    {
        if(i)cout<<" ";
        cout<<*ok;
        ok++;
        i++;
    }
}
