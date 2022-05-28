#include<bits/stdc++.h>

using namespace std;



int main()

{

     long long dp[100],x;
     memset(dp,0,sizeof(dp));
     dp[0]=-1;
     dp[1]=1; 
     dp[2]=2;
     for(int i=1;i<=90/2;i++)
     {
         dp[2*i]=dp[i]*dp[i]+1;
         dp[(2*i)+1]=dp[i]*dp[i+1]+2;
     }
     int t,k=1;
     cin>>t;
     while(t--)
     {
         cin>>x;
         cout<<"Case "<<k<<": ";
         for(int i=0;i<=100;i++)
         {
             if(x==dp[i])
             {
                 cout<<i<<endl;
                 break;
             }
         }
         k++;
     }
    return 0;
}
