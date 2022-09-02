#include<bits/stdc++.h>
using namespace std;

int max( int n, int m)
{
    if(n<m)
    return m;
    return n;
}
int min(int n,int m)
{
    if(n>m)
    return m;
    return n;
}
map<int  ,int>m1,m2;
int a[1000009];
vector< long long  > V;

long single_divisor(long n)
{
     long s=0,rt,p;
     rt = (int)sqrt(n);
     for(p = 1; p <= rt; p++)
     {
        if(n % p == 0)
        {
            if(m1[p]!=1)
            {
                V.push_back(p);
                m1[p]=1;
            }
            if(p * p != n and m1[n/p]!=1)
            {
                V.push_back(n / p);
                m1[n/p]=1;
            }
        }
    }
    return 0;
 }
int main()
{
   ios_base::sync_with_stdio(0);
   int n,i,j,k,l,mx=0;

   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>k;
       if(m2[k]!=1)
       single_divisor(k);
       m2[k]=1;
       mx=max(mx,k);
   }
   sort(V.begin(),V.end());
   k=0;
   for(i=1;;i++)
   {
       if(V[i-1]!=i)
       {
            cout<<i<<"\n";
            return 0;
       }
   }
    return 0;
}