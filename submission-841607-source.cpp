// Naimul Hasan SHadesh
// SOnargaon University

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    int x=n/m;
    int y=n-(x*m);

    cout<<x<<" "<<y<<" "<<m<<endl;

    return 0;
}