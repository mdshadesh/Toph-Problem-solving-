#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ar[20];
ll nm[10];

int main()
{
    ar[1]=1;
    ar[2]=6;
    ar[3]=36;
    ar[4]=180;
    string str;
    ll n,m,cnt;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>m;
        nm[4]=(m/ar[4]);
        m=m- (nm[4])*ar[4];

        nm[3]=(m/ar[3]);
        m=m- (nm[3])*ar[3];

        nm[2]=(m/ar[2]);
        m=m- (nm[2])*ar[2];

        nm[1]=(m/ar[1]);
        m=m- (nm[1])*ar[1];

        cout<<nm[1]+nm[2]+nm[3]+nm[4]<<endl;
        cout.flush();
        vector<ll>val;

        for(int i=0; i<nm[1]; i++)
            val.push_back(1);
        for(int i=0; i<nm[2]; i++)
            val.push_back(6);
        for(int i=0; i<nm[3]; i++)
            val.push_back(36);
        for(int i=0; i<nm[4]; i++)
            val.push_back(180);

        for(int i=0;i<val.size();i++)
        {
            if(i==0)
                cout<<val[i];
            else cout<<" "<<val[i];
        }
        cout<<endl;
        cout.flush();
        cin>>str;
    }
}