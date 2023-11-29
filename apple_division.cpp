#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector<int>
#define vl              vector<ll>
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
}

void place(vi &a, int i, ll s1, ll s2 , ll &ans) {
	if (i == a.size())
	{
		ans = min(ans, abs(s1 - s2));
		return;
	}
	place(a, i + 1, s1 + a[i], s2, ans);
	place(a, i + 1, s1, s2 + a[i], ans);
}
int main()
{
	JUDGE();
	FAST
	get(n);
	vi a(n);
	rep(i, 0, n - 1) cin >> a[i];
	ll ans = INT_MAX;
	place(a, 0, 0, 0, ans);
	cout << ans;
	return 0;
}