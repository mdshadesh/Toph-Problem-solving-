#include<bits/stdc++.h>
using namespace std;
int rem[1000001];
int main()
{
    int n,k;
    cin>>n>>k;
    set<int>s;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        rem[x%k]++;
    }
    long long ans = 0;
    int need = n/k;
    for(int i=0; i<k*2; i++)
    {
        if(rem[i%k]>need)
        {
            int needRem = rem[i%k]-need;
            ans+=needRem;
            rem[i%k] = need;
            rem[(i+1)%k]+=needRem;
        }
    }
    cout<<ans<<endl;

}