#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
struct DS{
	deque<int> dq;
	int rev = 0;
	long long sum = 0;
	void pop(){
		if(dq.size() == 0) return;
		if(rev){
			sum -= dq.front();
			dq.pop_front();
		}
		else{
			sum -= dq.back();
			dq.pop_back();
		}
	}
	void reverse(){
		rev ^= 1;
	}
	void calibrate(){
		while(dq.size() > MAX){
			reverse();
			pop();
			reverse();
		}
	}
	void print(){
		if (dq.empty()) {
			cout << "-\n";
			return;
		}
		if(rev) cout << dq.front() << '\n';
		else cout << dq.back() << '\n';
	}
	void push(int x){
		sum += x;
		if(rev) dq.push_front(x);
		else dq.push_back(x);
		calibrate();
	}
	int get(int i){
		int sz = dq.size();
		if(rev) i = sz - i - 1;
		return dq[i];
	}
	void repeat(int x){
		long long sz = dq.size();
		long long tot = sz * x;
		int i = 0;
		reverse();
		while(tot > 0 && dq.size() < MAX){
			push(get(i));
			i = (i + 1) % sz;
			tot--;
		}
		reverse();
	}
};
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	DS ds;
	// assert(MAX == 1e6);
	while(cin >> s){
		if(s == "PUSH"){
			int x;
			cin >> x;
			ds.push(x);
		}else if(s == "POP"){
			ds.pop();
		}else if(s == "PRINT"){
			ds.print();
		}else if(s == "SIZE"){
			cout << ds.dq.size() << '\n';
		}else if(s == "SUM"){
			cout << ds.sum << '\n';
		}else if(s == "REPEAT"){
			int x;
			cin >> x;
			ds.repeat(x);
		}
		else if(s == "REVERSE"){
			ds.reverse();
		}
	}
	return 0;
}
