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
	get(n);
	vector<pair<int, int>> a(n);
	vector<int>v;
	rep(i, 0, n - 1) 	cin >> a[i].first >> a[i].second;
	sort(all(a));
	int i = 0 , j = 0 , cnt = 1 , ans = 0;
	while (i < n) {
		if (a[i].first < a[j].second) {
			v.push_back(cnt);
			ans = max(cnt , ans);
			cnt++;
			i++;
		}
		else if ( a[i].first == a[j].second) {
			cnt++;
			ans = max(cnt, ans);
			v.push_back(cnt);
			i++; j++; cnt--;
		}
		else {
			cnt--;
			j++;
		}
	}
	cout << ans << endl;
	logarr(v);
	return 0;
}