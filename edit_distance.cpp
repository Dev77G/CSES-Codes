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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	JUDGE();
	FAST
	string s, t;
	cin >> s >> t;
	int n = s.size() , m = t.size();
	vi prev(m + 1) , cur(m + 1);
	for (int i = 0; i < m; i++)
		prev[i] = i;
	for (int i = 1; i <= n; i++) {
		cur[0] = i;
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1])
				cur[j] = prev[j - 1];
			else
				cur[j] = min({ cur[j - 1] , prev[j - 1] , prev[j] }) + 1;
		}
		prev = cur;
	}
	cout << prev[m];
	return 0;
}