#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    char s[100],rev[100];
    int len=0,i,j,flag=0;
    gets(s);

    // Length of the String

    while(s[len]!='\0')
        len++;

        // Reversing it
 for(i=len-1,j=0;i>=0,j<len;i--,j++)
 {
     rev[i]=s[j];
 }

 for(i=0;i<len;i++)
 {
     if(rev[i]!=s[i])
     {
         flag=1;
         break;
     }
 }

 if(flag==0)
 printf("Yes\n");
 else
    printf("No\n");

    return 0;

}