#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int sum=(N*(N+1))/2;
    int M;
    cin>>M;
    int temp=0,x;
    for(int i=1; i<=M; i++)
    {
        cin>>x;
        temp+=x;

    }
    int r=sum-temp;
    cout<<r<<endl;

}