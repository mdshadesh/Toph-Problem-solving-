#include<stdio.h>

int main()
{
  int n,flag=0,i=2;

  scanf("%d",&n);

  while(i<n)
  {
      if(n%i==0)
      {
          flag=1;
          break;
      }
     i++;

  }

  if(flag==0)
    printf("Yes\n");
  else
    printf("No\n");

    return 0;

}