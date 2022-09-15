using namespace std;
#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#ifdef shivang_ka_laptop
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
	#define booga cerr << "booga" << endl;
#else
	#define debug(...) 42;
	#define booga 9;
#endif


const int bit = 20;
const int N = 1e4;

void testcase(){
	int x,y,q;
	cin >> x >> y >> q;
	
	
	vector<long double> prob(y+1);
	
	long double eps = 1.0 / (long double)(y-x+1);
	for(int i = x; i <= y; i++){
		prob[i] = eps;
	}
	
	int sum = ~(0);
	
	for(int i = x; i <= y; i++){
		sum &= i;
	}
	
	vector<int> ans(N,sum);
	
	
	for(int i = 1; i <= N; i++){
		int which = -1;
		long double lar = 0;
		for(int j = 0; j <= y; j++){
			if(prob[j] >= lar){
				lar = prob[j];
				which = j;
			}
		}
		ans[i] = which;
		if(which == sum)break;
		
		vector<long double> naya(y+1);
		for(int j = 0; j <= y; j++){
			for(int k = x; k <= y; k++){
				naya[j & k] += prob[j] * eps;
			}
		}
		prob = naya;
	}
	while(q--){
		int n;
		cin >> n;
		cout << (n < N ? ans[n] : sum) << '\n';
	}
	
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	//cin >> tt;
	while(tt--){
		testcase();
	}
	return (0-0);
}