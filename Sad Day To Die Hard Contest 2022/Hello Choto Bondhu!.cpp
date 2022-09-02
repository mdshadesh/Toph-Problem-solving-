#include <iostream>
#include<cstring>

using namespace std;

int main() {
	int T,i,a;
	string n;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		cin>>n;
		a=(int)n[n.size()-1] -48;
		if(a<4) printf("%d\n",a*a);
		else {
			a=(a*a)%10;
			printf("%d\n",a);
		}
	}
	return 0;
}