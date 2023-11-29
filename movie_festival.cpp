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
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	JUDGE();
	FAST
	get(n);
	vector<pair<int, int>> v;
	rep(i, 0, n - 1) {
		get(x); get(y);
		v.push_back({y, x});
	}
	sort(v.begin(), v.end());
	int cnt = 1 , end = v[0].first, i = 1;
	while (i < n) {
		if (v[i].second >= end) {
			end = v[i].first;
			cnt++;
		}
		i++;
	}
	cout << cnt;
	return 0;
}