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
	get(x);
	get(n);
	set<int>a;
	multiset<int> s;
	a.insert(0); a.insert(x);
	s.insert(x);
	while (n--) {
		get(z);
		a.insert(z);
		auto it = a.find(z);
		it--;
		int l = *a.upper_bound(z);
		s.erase(s.find(l - *it));
		s.insert( z - *it );
		s.insert( l - z );
		cout << *s.rbegin() << " ";
	}
	return 0;
}