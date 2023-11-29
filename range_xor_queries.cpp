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
	get(n); get(q);
	vi a(n + 1, 0), b(n + 1, 0);
	rep(i, 1, n) cin >> a[i];
	int x = 0;
	rep(i, 1, n) {
		x = x ^ a[i];
		b[i] = x;
	}
	while (q--) {
		get(u);    get(v);
		int k = b[v] ^ b[u - 1] ;
		cout << k << endl;
	}

	return 0;
}