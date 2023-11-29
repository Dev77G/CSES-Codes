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
const int mod = 1e9 + 7;
void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int find(vi &p, vi &a , int n, int i) {
	if (a[i] < n) return i;
	return find(p, a, n, p[i]);
}
int main()
{
	JUDGE();
	FAST
	get(n);
	vi a(n + 1);
	a[0] = -1;
	rep(i, 1, n) cin >> a[i];
	vi p(n + 1);
	rep(i, 1, n) {
		p[i] = find(p, a, a[i], i - 1);
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";

	return 0;
}