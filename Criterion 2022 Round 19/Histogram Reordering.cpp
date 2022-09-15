#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 500005

ll a[sz];
vector<pair<ll,ll> >v;
map<ll,ll> mp;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n, m=0;
        cin>>n;
        ll mx=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            mx=max(mx,v[i].first*(n-i));
        }

        ll mn = INT_MAX;
        ll mxx = 0, ind=-1;
        ll amx=0, amn=INT_MAX, cnt=0, arekmn=INT_MAX;
        for(int i=n-1; i>=0; i--){
            ll val = v[i].first*(n-i);
            amx = max(amx,v[i].second);
            amn = min(amn,v[i].second);
            if(v[i].second<mn){
                cnt++;
            }
            else{
                arekmn = min(v[i].second,arekmn);
            }
            if(val == mx){
                if(ind==-1){
                    ind = i;
                    mn = amn;
                    mxx = amx;
                    amx=0;
                    amn = INT_MAX;
                    cnt=0;
                    arekmn = INT_MAX;
                }
                else{
                    if(max(mn-amn,0ll) == cnt && arekmn<mxx){
                        ind = i;
                        mn = min(amn,mn);
                        mxx = max(mxx,amx);
                        amx=0;
                        amn=INT_MAX;
                        cnt=0;
                        arekmn = INT_MAX;
                    }
                }
            }
        }
        for(int i=ind; i<v.size(); i++){
            mp[v[i].second]=1;
        }
        int key=1;
        for(int i=1; i<=n; i++){
            if(mp[i]){
                if(key){
                    for(int j=1; j<=n; j++){
                        if(mp[j]) cout<<j<<' ';
                    }
                }
                key=0;
            }
            else cout<<i<<' ';
        }
        cout<<endl;
        v.clear();
        mp.clear();

    }
    return 0;
}