/* Naimul hasan Shadesh */
/* Sonargoan University */

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int size = s.size();
    int f[10]={0},i,pos,max;

    for(i=0;i<size;i++)
    {
        f[s[i]-48]++;
    }
    max=0;
    for(i=9;i>=0;i--)
    {
      if(f[i]>=max)
      {
        max = f[i];
        pos = i;

      }
    }

    cout<<pos<<endl;

}