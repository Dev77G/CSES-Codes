#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define take(i,a)       for(int i=0; i<n; ++i) cin>>a[i];
#define vi              vector<int>
#define vl              vector<ll>
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9 + 7;
void judge() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main()
{
	judge();
	FAST
	get(n);
	get(x);
	vi a(n), dp(x + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n ; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n && i >= a[j] ; j++) {
			dp[i] = (dp[i] + dp[i - a[j]]) % mod;
		}
	}
	cout << dp[x];
	return 0;
}