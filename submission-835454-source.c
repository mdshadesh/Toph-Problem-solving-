#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,flag=0;
    char str1[100],str2[100];
    gets(str1);
    gets(str2);

    for(i=0;i<strlen(str1);i++)
    {
        flag=0;
        for(j=0;j<strlen(str2);j++)
        {
            if(str1[i]==str2[j])
            {
                flag=1;
                break;
            }

        }
        if(flag==0)
        break;
    }
if(flag==0)
        printf("No");
else
    printf("Yes");


}