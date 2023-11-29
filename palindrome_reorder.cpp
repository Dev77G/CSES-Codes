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
	string s;
	cin >> s;
	int n = s.size(), cnt = 0 , odd = -1;
	vi c(26);
	rep(i, 0, n - 1)  	 c[s[i] - 65]++;
	rep(i, 0, 25) if (c[i] & 1) cnt++;
	if (cnt > 1)
		cout << "NO SOLUTION";
	else {
		rep(i, 0, 25) {
			int csize = c[i] / 2;
			if (c[i] & 1) {
				odd = i; c[i]--;
			}
			c[i] -= csize;
			while (csize--)
				cout << char(i + 65);
		}
		if (odd != -1)
			cout << char(odd + 65);
		for (int i = 25 ; i >= 0 ; i-- ) {
			while (c[i]--)
				cout << char(i + 65);
		}
	}
	return 0;
}