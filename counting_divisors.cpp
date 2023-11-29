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
	get(t);
	while (t--) {
		get(n);
		int i, cnt = 0;
		for ( i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
			}
		}
		cnt *= 2;
		if ((i - 1) * (i - 1) == n) cnt--;
		cout << cnt << endl;
	}
	return 0;
}