#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector<int>
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int dp[1001][100001];
int main()
{
	JUDGE();
	FAST
	memset(dp, -1, sizeof(dp));
	get(n); get(x);
	vi a(n), h(n);
	rep(i, 0, n - 1)	cin >> a[i];
	rep(i, 0, n - 1)	cin >> h[i];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= x; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= x; j++) {
			if (a[i - 1] <= j)
				dp[i][j] = max(h[i - 1] + dp[i - 1][j - a[i - 1]], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	cout << dp[n][x];
	return 0;
}