#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,r;
    cin>>s;
    r=s;
    reverse(r.begin(),r.end());
    if(r==s)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}