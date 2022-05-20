#include <bits/stdc++.h>
using namespace std;

int main()
{
 string s;
 stack<char> a;

 cin>>s;

 for(int i=0;i<s.length();i++)
 {
  if(s[i] == '(' || s[i] == '{' || s[i] == '[')
   a.push(s[i]);
  else
  {
   if(a.empty())
   {
    cout<<"No"<<endl;
    return 0;
   }
   else if(s[i] == ')')
   {
    if(a.top() == '(')
    {
     a.pop();

    }
   }
   else if(s[i] == '}')
   {
    if(a.top() == '{')
     {
     a.pop();

    }
   }
   else if(s[i] == ']')
   {
    if(a.top() == '[')
     {
     a.pop();

    }
   }
  }
 }

 if(a.empty())
 {
        cout<<"Yes"<<endl;
  return 0;
 }
    else
     cout<<"No"<<endl;
}