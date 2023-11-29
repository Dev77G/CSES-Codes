#include <bits/stdc++.h>

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
#define take(i,a)       for(int i=0; i<n; ++i) cin>>a[i];
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
	int i = 0 , j = 0 , ans = 0 , finalans = 0 , n;
	get(t);
	n = t;
	vi a(t), b(t);
	while (t--) {
		cin >> a[i] >> b[i++];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	i = 0;
	while (i < n) {
		if (a[i] < b[j])
		{
			ans++;
			i++;
		}
		else {
			finalans = max( finalans, ans);
			ans--;
			j++;
		}
	}
	finalans = max (finalans, ans);
	cout << finalans;
	return 0;
}