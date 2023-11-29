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
	get(n); get(sum);
	vector<pair<int, int>> a;
	rep(i, 0, n - 1) {
		get(x);
		a.push_back({x, i});
	}
	int i;
	sort(a.begin(), a.end());
	for (i = 0; i < n - 2; i++) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			if (a[i].first + a[j].first + a[k].first == sum) {
				cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1;				i = n;
				break;
			}
			else if (a[i].first + a[j].first + a[k].first < sum)
				j++;
			else	k--;
		}
	}
	if (i != n + 1) cout << "IMPOSSIBLE";
	return 0;
}