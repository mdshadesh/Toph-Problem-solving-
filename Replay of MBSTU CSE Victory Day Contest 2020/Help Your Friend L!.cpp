#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
void test()
{
    char s[1000001];
    scanf(" %[^\n]",s);
    int n=strlen(s),i=1;
    if((s[0]>='A' && s[0]<='Z') && ((s[1]>='a' && s[1]<='z') || s[1]==' ') &&
        (s[n-1]=='.' || s[n-1]=='?' || s[n-1]=='!') && s[n-2]!=' ' ) {
        char t[1000001];
        int x=0,y=0;
        while(s[i]!='\0'){
            if(s[i]==' '){
                if(s[i-1]==' '){
                    printf("No\n");
                    return;
                }
                y++,t[x]='\0';
                for(int j=1;j<x;j++){
                    if(t[j]>='A' && t[j]<='Z'){
                        printf("No\n");
                        return;
                    }
                }
                x=0;
                i++;
            }
            else t[x++]=s[i++];
            if(i==n-1){
                for(int j=1;j<x;j++){
                    if(t[j]>='A' && t[j]<='Z'){
                        printf("No\n");
                        return;
                    }
                }
            }
        }
        printf("Yes\n");
    }
    else printf("No\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)test();
}