#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio ios_base::sync_with_stdio(false)
#define flush_off cin.tie(NULL)
#define mod 1000000007

void solve()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	string ans = s;
	int twos = 0, ones = 0;
	for(int i=0; i<n/2; ++i)
	{
		int ss = s[i]-'0';
		ss += (s[n-1-i]-'0');
		int tt = t[i]-'0';
		tt += (t[n-1-i]-'0');
		if(ss != tt)
		{
			if(ss+tt == 3 or ss+tt == 1) ones++;
			else twos++;
		}
	}

	if(n%2)
	{
		if(s[n/2]!=t[n/2]) ++ones;
	}
	int f = 1;
	if(ones%2 == 0)
	{
		if(twos%2 == 0)
		{
			twos/=2;
			ones/=2;
		}
		else if(ones)
		{
			twos/=2;
			ones = (ones+2)/2;
		}
		else f=0;
	}
	else f = 0;

	if(f)
	{
		for(int i=0; i<n/2; ++i)
		{
			int ss = s[i]-'0';
			ss += (s[n-1-i]-'0');
			int tt = t[i]-'0';
			tt += (t[n-1-i]-'0');
			if(ss != tt)
			{
				if(ss+tt == 3 or ss+tt == 1)
				{
					if(ones)
					{
						--ones;
						if(tt==0)
						{
							ans[i] = '1';
							ans[n-1-i] = '1';
						}
						else if(tt==2)
						{
							ans[i] = '0';
							ans[n-1-i] = '0';
						}
						else if(ss == 0)
						{
							ans[i] = '0';
							ans[n-1-i] = '0';
						}
						else
						{
							ans[i] = '1';
							ans[n-1-i] = '1';
						}
					}

					else
					{
						if(tt==0)
						{
							ans[i] = '0';
							ans[n-1-i] = '0';
						}
						else if(tt==2)
						{
							ans[i] = '1';
							ans[n-1-i] = '1';
						}
						else if(ss == 0)
						{
							ans[i] = '1';
							ans[n-1-i] = '1';
						}
						else
						{
							ans[i] = '0';
							ans[n-1-i] = '0';
						}
					}
				}
				else
				{
					if(twos)
					{
						--twos;
						ans[i] = s[i];
						ans[n-1-i] = s[i];
					}

					else
					{
						ans[i] = t[i];
						ans[n-1-i] = t[i];
					}
				}
			}

			else
			{
				ans[i] = '0';
				ans[n-1-i] = '0';
			}
		}

		if(n%2)
		{
			if(ones)
			{
				ans[n/2] = s[n/2];
			}
			else
			{
				ans[n/2] = t[n/2];
			}

		}

		cout<<ans<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}

int main()
{
	fastio;
	flush_off; //turn this off if cout needs to be flushed
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    cin>>t;
    while(t--) solve();
}