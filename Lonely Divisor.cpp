#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool s[100010];
ll cnt[100010];
vector <ll> v[100010];
vector < pair <ll, ll> > kres[150];

int main()
{
    ll i, j, n, m, l, r, t, k;

    for(i=1; i<=100000; i++)
    {
        for(j=i; j<=100000; j+=i) v[j].push_back(i), cnt[j]++;
    }
    //cout<<"*"<<endl;
    for(k=1; k<=128; k++)
    {
        for(i=1; i<=100000; i++)
        {
            ll len=v[i].size();
            ll p=-1;
            for(j=0; j<len; j++)
            {
                if(cnt[v[i][j]]==k)
                {
                    if(p==-1) p=v[i][j];
                    else
                    {
                        p=-1;
                        break;
                    }
                }
            }
            if(p==-1) continue;
            kres[k].push_back({i,p});
        }
        //cout<<k<<endl;

    }

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld %lld %lld", &l, &r, &k);
        pair <ll, ll> tmp={r, 1e6};
        ll res=upper_bound(kres[k].begin(), kres[k].end(), tmp)-kres[k].begin();
        tmp={l-1, 1e6};
        ll up=upper_bound(kres[k].begin(), kres[k].end(), tmp)-kres[k].begin();
        if(res==0) printf("-1\n");
        else if(kres[k][res-1].first<l) printf("-1\n");
        else
        {
            ll xx=0, yy=0;
            for(j=up; j<res; j++)
            {
                if(yy<=kres[k][j].second) yy=kres[k][j].second, xx=kres[k][j].first;
            }
            printf("%lld %lld\n", xx, yy);
        }
    }


    return 0;
}