#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vti(a,n) vi a(n);for(int i=0;i<n;i++)cin>>a[i];
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
	vector<pair<int, int>>a;
	get(n); get(m);
	for (int i = 0; i < n; i++) {
		get(x);
		a.push_back({x, i});
	}
	sort(a.begin(), a.end());
	int i = 0 , j = n - 1 ;
	while (i < j) {
		if ( a[i].first + a[j].first == m)
		{
			cout << a[i].second + 1 << " " << a[j].second + 1;
			i = n + 5;
			break;
		}
		if (a[i].first + a[j].first > m)
			j--;
		else i++;
	}
	if (i != n + 5)
		cout << "IMPOSSIBLE";
	return 0;
}