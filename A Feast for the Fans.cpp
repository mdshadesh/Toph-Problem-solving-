#include <bits/stdc++.h>
using namespace std;

map<string ,int > M={ {"January",0}
,{"February",1}
, {"March",2}
, {"April",3}
, {"May",4}
,{"June",5}
,{"July",6}
,{"August",7}
,{"September",8}
,{"October",9}
,{"November",10}
,{"December",11}
};
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
int poku[12][32];
int main()
{
    for(int i=0,d=0;i<12;i++)
    {
        for(int j=1;j<=days[i];j++,d++)
            poku[i][j]=d;
    }
    int tc,p,k,d;string s;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        cin>>s>>d;
        d=poku[ M[s] ][d];
        d%=67;
        int sea=d/10 +1;
        int api=d%10+1;
        cout<<"S0"<<sea;
        if(api<10)cout<<"E0"<<api;
        else cout<<"E10";
        cout<<endl;
    }
    return 0;
}