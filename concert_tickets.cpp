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

void judge() {
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
	judge();
	FAST
	oset<ll>s;
	get(n); get(m);
	vi a(n), b(m);
	rep(i, 0, n - 1) {
		get(x);
		s.insert(x);
	}
	// logarr(s);
	// s.erase(s.find_by_order(3));
	// logarr(s);
	while (m--) {
		get(y);
		if (s.empty()) { cout << -1 << " "; continue; }
		if ( *s.find_by_order(0) > y)
			cout << -1 << " ";
		else if (*s.find_by_order(0) == y)
		{
			cout << y << " ";
			s.erase(s.find_by_order(0));
		}
		else if (*s.find_by_order(s.order_of_key(y)) == y)
		{
			cout << y << " ";
			s.erase(s.find_by_order(s.order_of_key(y)));
		}
		else {
			cout << *s.find_by_order(s.order_of_key(y) - 1) << " ";
			s.erase(s.find_by_order(s.order_of_key(y) - 1));
		}
	}
	return 0;
}