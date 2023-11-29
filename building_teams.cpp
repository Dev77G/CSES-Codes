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
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int Find(int k, vi &par) {
	if ( par[k] == k ) return k;
	return par[k] = Find(par[k], par);
}
void Union(int a, int b, vi &par) {
	a = Find(a, par);
	b = Find(b, par);
	if (a != b)
		par[b] = a;
}
int main()
{
	JUDGE();
	FAST
	get(n);
	get(m);
	vi par(n + 1), towns;
	rep(i, 1, n) par[i] = i;
	while (m--) {
		get(a); get(b);
		Union(a, b, par);
	}
	int k = 0;
	rep(i, 1, n) {
		if (par[i] == i)
			k++;
	}
	if (k == 1) cout << "IMPOSSIBLE";
	else {
		int x = Find(1, par);
		rep(i, 1, n) {
			if (x  == Find(i, par) )
				cout << 1 << " ";
			else
				cout << 2 << " ";
		}
	}
	return 0;
}