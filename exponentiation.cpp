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
const int M = 1e9 + 7;
void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll Pow(ll a, ll b) {
	if (b == 2) return (a * a) % M;
	if (b == 1) return a;
	if (b & 1) return ( ( (a * (Pow(a, b / 2) % M )) % M ) * (Pow(a, b / 2) % M) ) % M;
	return ( (Pow(a, b / 2) % M ) * (Pow(a, b / 2) % M) ) % M;
}
int main()
{
	JUDGE();
	FAST
	get(t);
	while (t--) {
		getl(a); getl(b);
		if ( b == 0) cout << 1 << endl;
		else
			cout << Pow(a, b) << endl;
	}
	return 0;
}