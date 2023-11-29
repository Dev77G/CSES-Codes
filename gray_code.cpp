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
	string s;
	vector < vector < int>>v(n + 1);
	rep(i, 0, (1 << n) - 1) {
		v[__builtin_popcount(i)].push_back(i);
	}
	// rep(i, 0, v.size() - 1) cout << v[i].size() << endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}

	// rep(i, 0, n - 1) s.push_back('0');
	// show(0, s, n - 1);
	return 0;
}