#include <bits/stdc++.h>

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define take(i,n,a)       for(int i=0; i<n; ++i) cin>>a[i];
#define vi              vector<int>
#define vl              vector<ll>
#define all(a)          a.begin(),a.end()
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

void judge() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	judge();
	FAST
	get(n);
	get(m);
	getl(k);
	vl a(n), b(m);
	take(i, n, a);
	take(i, m, b);
	sort(all(a));
	sort(all(b));

	int i = 0, j = 0, cnt = 0;

	while (i < n && j < m) {
		if (a[i] - k <= b[j] && a[i] + k >= b[j]) {
			//cout << a[i] << " " << b[j] << endl;
			i++;
			j++;
			cnt++;
		}
		else if (a[i] - k > b[j] )
			j++;
		else i++;
	}
	cout << cnt;
	return 0;
}