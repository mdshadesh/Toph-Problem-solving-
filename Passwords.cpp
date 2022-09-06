#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int i,d=0,l=0,count=0,u=0;
        for(i=0; s[i];i++)
        {
            if(isdigit(s[i]))
                d++;
            else if(isupper(s[i]))
                u++;
            else
                l++;
            if(d && u && l)
                count++,d=0,l=0,u=0;
        }
        cout<<count<<endl;
    }
}