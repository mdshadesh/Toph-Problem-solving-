#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int test=0;test<t;test++)
    {
        int u;
        cin >> u;
        if(u<0)
        {
            u = u*(-1);
        }
        cout << u << "\n";
    }
}