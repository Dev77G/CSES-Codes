#include <bits/stdc++.h>
using namespace std;
#define ll long long

void func( multiset<ll>&towers , int key ) {
	auto it = towers.end();
	it--;
	if ( (*it) <= key ) {
		towers.insert(key);
		return ;
	}
	auto kt = towers.lower_bound(key + 1);
	towers.erase(kt);
	towers.insert(key);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n , count = 1 ;
	cin >> n ;
	multiset<ll>p;
	ll a[n];
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n - 1; i++) {
		if (a[i] <= a[i + 1]) count++;
	}
	if ( count == n ) { cout << n; return 0; }
	p.insert(a[0]);
	for (ll i = 1 ; i < n ; i++) {
		func(p, a[i]);
	}
	cout << p.size();
	return 0;
}
