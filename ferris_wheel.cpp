#include <bits/stdc++.h>

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define take(i,n,a)       for(int i=0; i<n; ++i) cin>>a[i];
#define vi              vector<int>
#define vl              vector<ll>
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
	get(n); get(k);
	vi a(n);
	take(i, n, a);
	sort(a.begin(), a.end());
	int i = 0, j = n - 1, cnt = 0;
	while (i <= j) {
		if (a[i] + a[j] <= k) {
			cnt++;
			i++; j--;
		}
		else {
			cnt++;
			j--;
		}
	}
	cout << cnt;

	return 0;
}