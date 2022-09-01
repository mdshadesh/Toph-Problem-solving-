#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lim 5000006
#define inf 10000000000000000000
#define md 1000000007
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
const int H=2500,W=2500;
ll tree[H+10][W+10];

void update(int x,int y,int val)
{
    while(x<=W){
        for(int i=y;i<=H;i += i &(-i))tree[x][i]+=val;
        x += x&(-x);
    }
}
ll query(int x,int y)
{
    ll sum=0;
    while(x>0){
        for(int i=y;i>0; i -= i & (-i))sum+=tree[x][i];
        x -= x & (-x);
    }
    return sum;
}
void rec(pair<int,int>a, pair<int,int>b,int val)
{
    update(a.first,a.second,val);
    update(b.first+1,a.second,-val);
    update(a.first,b.second+1,-val);
    update(b.first+1,b.second+1,val);
}
int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int i=1;
    while(q--)
    {
        int t;
        pair<int,int>a,b;
        scanf("%d %d %d %d %d",&t,&a.first,&a.second,&b.first,&b.second);

        if(t==1)
        {
            int k= query(a.first,a.second);
            rec(a,b,-k);
            rec(a,b,i);
            i++;
        }
        else if(t==2)
        {
            int k = query(a.first,a.second);
            rec(a,b,-k);
        }
        else
        {
            ll aa =query(a.first,a.second);
            ll bb =query(b.first,b.second);
            if(aa==bb){
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
}