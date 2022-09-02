#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll arr[1104],freq[1104];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int test,tc=1;
    cin>>test;
    while(test--){
        int n,q;
        map<ll,ll>maps,rev;
        int mc = 0;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            maps[arr[i]];
        }
        for(auto &v: maps)
        {
            v.second = ++mc;
            rev[mc] = v.first;
        }
        for(int i = 1; i <= n; i++)
            arr[i] = maps[arr[i]];
        cout<<"Case "<<tc++<<":"<<endl;
        while(q--){
            int type,l,r;
            cin>>type>>l>>r;
            if(type==1){
                int j = 1,i;
                for(i = l; i <= r; i++)
                    freq[j++] = arr[i];
                for(i = l; i <= r; i++)
                    arr[i] = freq[--j];
            }
            else{
                memset(freq,0,sizeof(freq));
                int i;
                for(i = l; i <= r; i++)
                    freq[arr[i]]++;
                for(i = 1; i < 1100; i++)
                {
                    freq[i] += freq[i-1];
                    if(freq[i] >= (r-l+1)/2 + 1)
                    {
                        cout << rev[i] << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}