#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         ll a; cin>>a
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector<int>
#define vl              vector<ll>
#define getv(a,n)       vi a(n); rep(i,0,n-1) cin>>a[i];
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define ump             unordered_map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vl,greater<ll>>
#define reset(a, b)     memset(a, b, sizeof(a))
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vpipii          vector<pair<int,pii>>
#define vpii            vector<pii>
#define vvi				vector<vi>
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
	get(a); get(b);
	if (b < a) swap(a, b);
	vvi dp(a + 1, vi(b + 1));
	for (int i = 1; i <= b; i++)
		dp[1][i] = i - 1;

	for (int i = 2; i <= a; i++) {
		for (int j = i + 1; j <= b ; j++) {
			dp[i][j] = i * j;
			for (int k = 1 ; k <= j / 2 ; k++) {
				dp[i][j] = min(dp[i][j] , dp[min(i, k)][max(i, k)] + dp[min(i, j - k)][max(i, j - k)]);
			}
			for (int k = 1 ; k <= i / 2 ; k++) {
				dp[i][j] = min(dp[i][j] , dp[min(k, j)][max(k, j)] + dp[min(i - k, j)][max(i - k, j)]);
			}
			dp[i][j]++;
		}
	}
	for (int i = 1; i <= a; i++) {
		cout << endl;
		for (int j = 1; j <= b ; j++) cout << dp[i][j] << " ";
	}
	return 0;
}