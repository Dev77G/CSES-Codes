#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector<int>
#define vl              vector<ll>
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9 + 7;
void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main()
{
	JUDGE();
	FAST
	get(n);
	vector<vi> dp(n + 1, vi (n + 1));
	vector<string> s(n);
	rep(i, 0, n - 1)	cin >> s[i];
	if (s[n - 1][n - 1] == '*' || s[0][0] == '*') {	cout << 0; return 0;}
	dp[n - 1][n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1 ; j >= 0 ; j--) {
			if (s[i][j] == '.')
				dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % mod;
		}
	}
	cout << dp[0][0];
	return 0;
}