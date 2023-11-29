#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         ll a; cin>>a
#define putyes          cout<<"YES\n"
#define putno           cout<<"NO\n"
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector<int>
#define vl              vector<ll>
#define getv(a,n)       vi a(n); rep(i,0,n-1) cin>>a[i];
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define all(x)          x.begin(), x.end()
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1000000007;
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
	get(t);
	vi q(t);
	rep(i, 0, t - 1)
	cin >> q[i];
	int n = *max_element(all(q));
	int dp[n + 1][2];
	dp[1][0] = 1 ;
	dp[1][1] = 1 ;
	rep(i, 2, n) {
		dp[i][1] = ((4LL * dp[i - 1][1] ) % mod + dp[i - 1][0] % mod) % mod;
		dp[i][0] = ((2LL * dp[i - 1][0]) % mod + dp[i - 1][1] % mod) % mod;
	}
	rep(i, 0, t - 1) cout << (dp[q[i]][0] + dp[q[i]][1]) % mod << endl;
	return 0;
}