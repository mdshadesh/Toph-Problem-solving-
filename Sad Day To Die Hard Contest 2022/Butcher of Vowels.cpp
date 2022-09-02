#include <iostream>

using namespace std;
#include<stdio.h>
#include<string.h>

int main(void)
{
    int  second=0, third=0, fourth=0,i,T,kase;

     scanf("%d",&T);
     for(kase=1; kase<=T; kase++)
	 {
        int first=0;
        char sentence[1000];
        scanf("%s",&sentence);
        for(i=0; sentence[i]!='\0'; i++)
		{
           if('a'==sentence[i] || 'e'==sentence[i] || 'i'==sentence[i] || 'o'==sentence[i]  || 'u'==sentence[i])
               first++;
        }
    if(first>0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
        }
    }
}
