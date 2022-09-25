#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,ss;
map<char,char>mp;

int main()
{
  mp[')']='(';
  mp[']']='[';
    ll i, ans, mx=0, len, ok=0;
    while(cin>>s)
    {
      ok=0,mx=0;
      stack<char>st;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='('||s[i]=='[')
        {
            st.push(s[i]);
        }
        if(i>0)
        {
            if(s[i]==']'||s[i]==')')
            {
            if(!st.empty())
            {
                if(st.top()==mp[s[i]])
                {
                    ok+=2;
                    st.pop();
                }
                else
                {
                  while(!st.empty())st.pop();
                }
                mx=max(mx,ok);
             }
           if(st.empty())
           {
            mx=max(mx,ok);ok=0;
           }
          }
        }
    }
    cout<<mx<<endl;
  }
}