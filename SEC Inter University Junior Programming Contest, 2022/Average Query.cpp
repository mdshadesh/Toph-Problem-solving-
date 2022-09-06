#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 100009
#define sz1 1001
#define mod 1000000007
#define mod1 998244353
#define pr1 67
#define pr2 61
#define f first
#define s second
#define pa pair<ll,ll>
#define vec array<ll,4>
const ll mx=2000000000000000000ll;
ll cnt[sz],arr[sz],brr[sz],nn;
std::vector<ll> prime;
map<ll,ll>mp;
std::vector<pa> vv;
std::vector<ll> divisor;
void generateDivisors(int curIndex,ll curDivisor)
{
    if (curIndex == nn) {
        divisor.push_back(curDivisor);
        return;
    }
 
    for (int i = 0; i <= vv[curIndex].s; ++i) {
        generateDivisors(curIndex + 1, curDivisor);
        curDivisor *= vv[curIndex].f;
    }
}
void ber_kor(ll num)
{
    vv.clear();
    divisor.clear();
    for(ll u:prime)
    {
        if(u*u>num)
            break;
        int as=0;
        while(num%u==0)
            as++,num/=u;
        if(as)
            vv.push_back({u,as}); 
    }
    if(num>1)
        vv.push_back({num,1});
    nn=vv.size();
    generateDivisors(0,1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int test_case=1;
    for(int i=2;i<sz;i++)
    {
        if(!brr[i]){
            prime.push_back(i);
        for(int j=i;j<sz;j+=i)
            brr[j]=1;
    }
    }
    for(int cs=1;cs<=test_case;cs++)
    {
    ll n,x;
    cin>>n>>x;
    std::vector<pa> v,v1;
    int id=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==x)
            id=i;
        if(arr[i]<=x)
            v.push_back({x-arr[i],i});
        else
            v1.push_back({arr[i]-x,i});
    }
    if(id==-1)
    {
        sort(v.rbegin(),v.rend());
        sort(v1.begin(),v1.end());
        ll mni=-1,mxi=-1,val1=-1,val2=-1;
        for(pa u:v)
        {
            ber_kor(u.f);
            for(ll uu:divisor)
                mp[uu]=u.s;
        }
        for(pa u:v1)
        {
            ber_kor(u.f);
            for(ll uu:divisor)
            {
                if(mp.find(uu)!=mp.end())
                {
                    ll id=mp[uu];
                    ll a1=u.f/uu;
                    ll b1=(x-arr[id])/uu;
                    assert(x>arr[id]);

                    if(mni==-1 || (a1+b1)<(val1+val2))
                        mni=u.s,mxi=id,val1=b1,val2=a1;
            }
          }
      }
      if(mni==-1)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        ll sum1=0;
        for(int i=1;i<=n;i++)
        {
            if(i==mni)
                cout<<val1<<" ",sum1+=val1*arr[i];
            else if(i==mxi)
                cout<<val2<<" ",sum1+=val2*arr[i];
            else
                cout<<"0 ";
        }
        assert(sum1%(val2+val1)==0);
        sum1/=(val1+val2);
        assert(sum1==x);
        cout<<"\n";
    }
    }
    else
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            if(i==id)
                cout<<"1 ";
            else
                cout<<"0 ";
     }
    }
   }
  return 0;
}