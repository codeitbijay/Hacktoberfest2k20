#include<bits/stdc++.h>
using namespace std;

#define int long long
#define scan(a,n)  for(int i = 0; i < n;i++)cin >> a[i];
#define print(a,n)  for(int i = 0;i < n;i++)cout <<a[i] <<' ';cout<<endl;
#define w(x)  int x; cin>>x; while(x--)
#define endl  '\n'
#define vi  vector<int>

const int inf = 1e9;
// Tushar Goyal : Chalie Shuru karte hai
#define db(...) 		__f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void solve()
{
	int n, x;
	cin >> n >> x;
	vi coins(n);
	scan(coins, n);

	vi dp(x + 1, inf);

	dp[0] = 0;

	for (int i = 1 ; i <= x ; i++)
	{
		for (int c : coins)
		{
			if (i - c >= 0)
			{
				dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
		// db(i, dp[i]);
	}

	if (dp[x] != inf)cout << dp[x] << endl;
	else cout << -1 << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}