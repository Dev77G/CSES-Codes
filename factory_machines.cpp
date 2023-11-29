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
#define getv(a,n)       vl a(n); rep(i,0,n-1) cin>>a[i];
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define all(x)          x.begin(), x.end()
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9 + 7;
void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool check(vl &a, ll &mid, ll t, ll &n) {
	for (int i = 0; i < n; i++) {
		t -= (mid / a[i]);
		if (t <= 0) return true;
	}
	return false;
}

int main()
{
	JUDGE();
	FAST
	getl(n);
	getl(t);
	getv(a, n)
	ll low = 1 , high = t**max_element(all(a)) , mid , ans;
	while (low <= high) {
		mid = (low + high) >> 1;
		bool k = check(a, mid, t, n);
		if (k) {
			high = mid - 1;
			ans = mid;
		}
		else low = mid + 1;
	}
	cout << ans;
	return 0;
}