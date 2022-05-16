
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, A, B, result;
    cin>>t;
    for(int i = 1; i <= t; i++)
    {
        cin>>A>>B;
        result = A*A + B*B;
        cout<<"Case "<<i<<": "<<result<<endl;
    }
}