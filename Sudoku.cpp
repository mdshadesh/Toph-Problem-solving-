#include<bits/stdc++.h>
#include<map>
using namespace std;

char arr[10];
int sum=0,i,flag=0;

int main()
{
    while (flag<9)
    {
        scanf ("%s",&arr);
        for (i=0;i<9;i++) 
        sum+=arr[i]-48;
        flag++;
    }
    if (sum==405) 
    printf ("Congratulations!");
    else 
    printf ("Oh No!");
    cout<<endl;
}