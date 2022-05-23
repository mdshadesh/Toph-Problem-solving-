/* Naimul Hasan Shadesh*/
/* Sonargaon university */
#include <iostream>
#include<stdio.h>
#include<math.h>

using namespace std;


int main()
{

    double a;
    scanf("%lf",&a);
    int i;

       a=floor(a);

    printf("[");
    for(i=0;i<((int)a/10);i++)
        printf("+");
    for(i=0;i<10-(a/10);i++)
        printf(".");

    printf("] ");

    printf("%d%c",(int)a,37);

}
