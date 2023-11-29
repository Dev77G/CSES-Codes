#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         ll a; cin>>a
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector< int >
#define vl              vector< ll >
#define getv(a,n)       vi a(n); rep(i,0,n-1) cin>>a[i];
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define ump             unordered_map
#define pq_max          priority_queue< ll >
#define pq_min          priority_queue< ll , vl , greater<ll> >
#define reset(a, b)     memset(a, b, sizeof(a))
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vipii           vector<pair<int,pii>>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define pb              emplace_back
#define endl            "\n"
#define MAX(x)			*max_element(all(x))
#define MIN(x)			*min_element(all(x))
#define SUM(x)			accumulate(all(x), 0LL)
#define FIND(x, y) 		binary_search(all(x), y)
#define lb 				lower_bound
#define ub 				upper_bound
#define mpii 			map<int ,int>
#define umpii 			unordered_map<int ,int>
#define precise(n)      cout<<fixed<<setprecision(n)
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TIME            cout<<"\nTime in secs: "<< (float)clock() / CLOCKS_PER_SEC;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
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
	get(k);
	getv(a, n);
	vector<vi> dp(n + 1 , vi(k + 1));
	rep(i, 0, n) dp[i][0] = 1;
	for (int i = n - 1; i >= 0; --i)
		for (int j = 1; j <= k ; ++j)
		{
			int pick = 0 , not_pick = dp[i + 1][j];
			if ( a[i] <= j ) pick = dp[i][j - a[i]];
			dp[i][j] = ( pick + not_pick ) % mod;
		}
	cout << dp[0][k];
	return 0;
}