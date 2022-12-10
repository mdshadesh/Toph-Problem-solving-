#include <stdio.h>
int main(){
	char s[33];
	int i, l, a=0, b=0;
	scanf(" %s", s);
	l=strlen(s);
	for(i=0;i<l;i++){
		a*=2;
		b*=2;
		if(s[i]=='1')a++;
		else if(s[i]=='2')b++;
		else if(s[i]=='3'){a++;b++;}
	}
	printf("%d %d %d", l, a, b);
	return 0;
}