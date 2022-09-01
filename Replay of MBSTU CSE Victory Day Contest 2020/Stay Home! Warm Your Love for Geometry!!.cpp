#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int T;
	cin>>T;
	while (T--){
		double AB, BC, x, y, z, s, c;
		cin>>AB>>BC;
		c=sqrt((AB*AB)+(BC*BC));
		s=AB/c;
		z=s*BC;
		y=sqrt((BC*BC)-(z*z));
		x=c-y;
		cout<<setprecision(6)<<fixed<<(x*x)+(y*z)-(z*z)<<endl;
	}
	return 0;
}