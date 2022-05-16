#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, m;
    double ha, ma, result;
    cin>>h>>m;
    ha = (h*60+m)*0.5;
    ma = m*6;
    //cout<<ha<<endl;
    //cout<<ma<<endl;
    result = abs(0.5*(60*h-11*m));
   // cout<<result<<endl;
    if(result > 180)
    {
        result = 360 - result;
    }
    printf("%.7lf\n", result);

}