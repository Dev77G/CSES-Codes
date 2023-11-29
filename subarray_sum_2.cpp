#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define put(a)          cout<<a<<" "
#define putn(a)         cout<<a<<"\n"
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector< int >
#define vl              vector< ll >
#define ump             unordered_map
#define pq_max          priority_queue< ll >
#define pq_min          priority_queue< ll , vl , greater<ll> >
#define reset(a, b)     memset(a, b, sizeof(a))
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vipii           vector<pair<int,pii>>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define pb              emplace_back
#define precise(n)      cout<<fixed<<setprecision(n)
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TIME            cout<<"\nTime in secs: "<<(float)clock()/CLOCKS_PER_SEC;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;

void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
//For values to be in descending order change less to greater in the line above
//For multiset change less to less_equal
//*s.lower_bound(k) , *s.upper_bound(k) , s.insert(k) , s.erase(k);
//finding no. of elements smaller than k : s.order_of_key(k)
//finding kth element : *s.find_by_order(k)

int main()
{
	JUDGE();
	FAST
	getl(n);
	getl(target);
	vl a(n);
	rep(i, 0, n - 1)
	cin >> a[i];
	oset<ll>s;
	rep(i, 1, n - 1) a[i] += a[i - 1];
	// logarr(a);
	ll cnt = 0;
	if (a[0] == target) cnt++;
	s.insert(a[0]);
	rep(i, 1, n - 1) {
		ll find = a[i] - target;
		if (a[i] == target) cnt++;
		// cout << find << endl;
		cnt += s.order_of_key(find + 1) - s.order_of_key(find);
		s.insert(a[i]);
	}
	cout << cnt;
	return 0;
}