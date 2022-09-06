#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Mrr[100004];
ll given[100004];
ll Tree[400005];
void rivalryfriends()
{
    ll N = 100000;
    for(ll i=0;i<=100000;i++){
        Mrr[i] = i;
    }
    for(ll i=2;i<=100000;i++){
        if(Mrr[i] == i){
            for(ll j=i;j<=100000;j+=i){
                Mrr[j] = Mrr[j] - (Mrr[j]/i);
            }
        }
    }
    return;
}

void SegInit(ll node , ll s , ll e)
{
    if(s==e){
        Tree[node] = given[s] ; return;
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    SegInit(l,s,mid);
    SegInit(r,mid+1,e);
    Tree[node] = Tree[l] + Tree[r];
}
void SegUpdate(ll node, ll s, ll e, ll in, ll x)
{
    if(in<s || in>e) return;
    if(s==in && e==in){
        Tree[node] = x; return;
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    SegUpdate(l,s,mid,in,x);
    SegUpdate(r,mid+1,e,in,x);
    Tree[node] = Tree[l] + Tree[r];
}

ll SegQuery(ll node, ll s, ll e, ll x, ll y)
{
    if(x>e || y<s){
        return 0;
    }
    if(s>=x && e<=y){
        return Tree[node];
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    ll q1 = SegQuery(l,s,mid,x,y);
    ll q2 = SegQuery(r,mid+1,e,x,y);
    return q1+q2;
}
int main()
{
    rivalryfriends();
    ll n,q;
    scanf("%lld%lld",&n,&q);
    ll a;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a);
        ll val = Mrr[a];
        given[i] = val;
    }
    SegInit(1,1,n);
    ll check , b , c;
    ll temp;
    ll ans ;
    while(q--){
        scanf("%lld%lld%lld",&check,&b,&c);
        if(check == 1){
            temp = Mrr[c];
            SegUpdate(1,1,n,b,temp);
        }
        else{
           ans = SegQuery(1,1,n,b,c);
           printf("%lld\n",ans);
        }
    }
    return 0;
}