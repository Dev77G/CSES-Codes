#include <bits/stdc++.h>
using namespace std;

#define get(a)          int a; cin>>a
int count(vector<int>&dp, int n, int ans) {
	if (n == 0) return 0;
	if (n < 10) return 1;
	if (dp[n] != 0) return dp[n];
	int n1 = n;
	while (n) {
		int x = n % 10;
		if (x != 0)
			ans = min(ans, count(dp, n1 - x, ans) );
		n /= 10;
	}
	return dp[n1] = ans + 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>dp(n + 1);
	cout << count(dp, n, n);
	return 0;
}