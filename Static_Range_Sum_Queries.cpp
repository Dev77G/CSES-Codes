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
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	JUDGE();
	FAST
	get(n);
	get(q);
	vl a(n + 1);
	a[0] = 0;
	rep(i, 1, n ) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
//	for (auto i : a) cout << i << " ";
	while (q--) {
		get(c);
		get(d);
		cout << a[d] - a[c - 1] << endl;
	}
	return 0;
}