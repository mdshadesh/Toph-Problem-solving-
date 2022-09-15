#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

int main()
{
	int t, n;
	int ara[1005][1005];
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n % 2 == 0){
			cout << "-1\n";
			continue;
		}
		for(int K = 1; K <= n; K++){
			ara[K][K] = K;
			
			int i = K, j = K;
			while(i && j <= n){
				ara[i][j] = K;
				
				i--;
				j++;
			}
			
			i = j = K;
			i++;
			j--;
			while(i <= n && j){
				ara[i][j] = K;
				i++;
				j--;
			}
		}
		
		int v = 1;
		for(int K = 2; K <= n; K += 2){
			int i = n, j = K;
			
			while(i && j <= n){
				ara[i][j] = v;
				i--;
				j++;
			}
			v++;
		}
		v++;
		for(int K = 2; K <= n; K += 2){
			int i = K, j = 1;
			
			while(i && j <= n){
				ara[i][j] = v;
				i--;
				j++;
			}
			v++;
		}
		for(int K = 1; K <= n; K++){
			for(int L = 1; L <= n; L++) cout << ara[K][L] << ' ';
			cout << "\n";
		}
	}
	return 0;
}