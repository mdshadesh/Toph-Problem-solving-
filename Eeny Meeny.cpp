#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string rhyme;
	getline(cin, rhyme);
	int words = 1;
	for(int i = 0; i<rhyme.length(); ++i) 
    {
		if(rhyme[i] == ' ') words++;
	}
	int n; cin >> n;
	string names[n];
	set<int> in;
	for(int i = 0; i<n; ++i) 
    {
		cin >> names[i];
		in.insert(i);
	}
	
	int pos = 0;
	vector<int> first, second;
	bool f = true;
	while(in.size()) 
    {
		pos = (pos+words-1)%in.size();
		auto it = in.begin();
		for(int i = 0; i<pos; ++i) 
        {
			it++;
		}
		if(f) first.push_back(*it);
		else  second.push_back(*it);
		in.erase(it);
		
		f = !f;
	}
	cout << first.size() << endl;
	for(int i = 0; i<first.size(); ++i) 
    {
		cout << names[first[i]] << endl;
	}
	cout << second.size() << endl;
	for(int i = 0; i<second.size(); ++i) 
    {
		cout << names[second[i]] << endl;
	}
	
	return 0;
}