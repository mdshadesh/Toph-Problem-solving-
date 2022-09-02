#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int
vector < pair < ll, ll > > ara, moves;
int main()
{
    ll n,k,x0,y0,x,y;
    bool flag = true;
    cin>>n>>k>>x0>>y0;
    for(ll i = 1; i <= n; i++)
    {
        cin>>x>>y;ara.push_back({x,y});
    }
    for(ll i = 1; i <= k; i++)
    {
        cin>>x>>y;
        moves.push_back({x,y});
    }
    for(ll i = 0; i < ara.size(); i++)
    {
        ll tmpx = ara[i].first - x0;
        ll tmpy = ara[i].second - y0;
        ll j = 0;
        for( ; j < moves.size(); j++)
        {
           ll forx = -1;
           ll fory = -1;
           if(tmpx==0 && moves[j].first==0) 
              forx = -2;
              else
              {
                if((tmpx > 0 && moves[j].first > 0) || (tmpx < 0 && moves[j].first < 0))if(tmpx % moves[j].first == 0) 
                   forx = tmpx / moves[j].first;
              }
              if(tmpy == 0 && moves[j].second == 0) 
                  fory = -2;
              else
              {
                if((tmpy > 0 && moves[j].second > 0) || (tmpy < 0 && moves[j].second < 0))
                   if(tmpy % moves[j].second == 0) 
                       fory = tmpy / moves[j].second;
              }
              if(forx == -1 || fory == -1) 
                 continue;
              if(forx == -2 || fory == -2) 
                  break;
              if(forx == fory) 
                break;
                }
                if(j == moves.size())
                {
                    flag = false;break;
                }
                x0 = ara[i].first;
                y0 = ara[i].second;
            }
            if(!flag) 
               printf("No\n");
            else 
               printf("Yes\n");
}