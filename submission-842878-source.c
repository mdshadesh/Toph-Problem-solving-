#include<stdio.h>
#include<string.h>

int main()
{
    char s[30];
    int i,a=0,b=0;
    gets(s);

    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='(')
            a++;
        if(s[i]==')')
            b++;
    }
    if(s[0]==')')
        printf("No\n");
    else if(a==b)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}