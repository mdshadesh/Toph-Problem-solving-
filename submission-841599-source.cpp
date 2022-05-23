/* Naimul Hasan Shadesh */
/* SOnargaon University */

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    string st[t+1];
    string s;
    int ac ;
    int len;
    int mxl=1;
    string cop;
    for(int i=0;i<t;i++)
	{
        cin>>s;
        len = s.size();
        ac = len -1;
        cop="";
        if(ac==1)
		{
            s+="a"; st[i] = s;
        }
        else if(ac%2 == 1)
		{
            for(int j=0;j<len-1;j++)
                cop+=s[j];
             st[i] = cop;
        }
      else
		{
        st[i] = s;
      }
      len = st[i].size();
      mxl = max(mxl,len);
    }
    int mid = mxl/2;
    int m;
    int space;
    for(int i=0;i<t;i++)
	{
        len = st[i].size();
        m = len/2;
        space = mid - m;
        for(int j=1;j<=space;j++)
            printf(" ");
        cout<<st[i]<<endl;
    }
    return 0;
}