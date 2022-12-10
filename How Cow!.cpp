#include <iostream>

using namespace std;
#include<stdio.h>

int main()
{
	int t;
	float r;
	scanf("%d",&t);
	while(t--){
		scanf("%f",&r);
		printf("%.3f\n",r*r*3.1416);
		}
	return 0;
}