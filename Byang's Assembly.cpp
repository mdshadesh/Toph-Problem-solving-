#include <bits/stdc++.h>
using namespace std;

string cmd[1010]; int x[1010];
char p[1010], q[1010]; map <char, int> reg;
int main() 
{
	std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); int i = 0; string s;
	while (cin >> s) 
    {
		cmd[i] = s;
		if(s == "INC") cin >> p[i];
		else if(s == "LOD") cin >> p[i] >> x[i];
		else if(s == "ADD" || s == "MUL" || s == "CMP") cin >> p[i] >> q[i];
		else if(s != "HLT") cin >> x[i];
		++i;
	}
	
	int j = 0;
	while(j < i) 
    {
		j = reg['P'];
		s = cmd[j];
		if(s == "HLT") break;
		else if(s == "LOD") reg[p[j]] = x[j];
		else if(s == "INC") ++reg[p[j]];
		else if(s == "ADD") reg[p[j]] += reg[q[j]];
		else if(s == "MUL") reg[p[j]] *= reg[q[j]];
		else if(s == "CMP") reg['C'] = (reg[p[j]] > reg[q[j]]) ? 1 : (reg[p[j]] < reg[q[j]]) ? -1 : 0;
		else if(s == "JMP" || (s == "JCZ" && reg['C'] == 0) || (s == "JCP" && reg['C'] > 0) || (s == "JCN" && reg['C'] < 0)) 
        {
			reg['P'] = x[j] - 1;
		}
		++reg['P'];
	}
	
	for(auto z = 'A'; z <= 'F'; ++z)
		cout << reg[z] << " ";
	cout << reg['P'] << endl;
}