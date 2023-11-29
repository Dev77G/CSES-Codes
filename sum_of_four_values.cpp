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
#define f               first
#define s               second
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
	get(n); get(x);
	vector<pair<int, int>> a;
	rep(i, 0, n - 1) {
		get(z);
		a.push_back({z, i});
	}
	sort(a.begin(), a.end());
	bool flag = true;
	for (int i = 0; i < n - 3 && flag ; i++) {
		for (int j = i + 1; j < n - 2 && flag ; j++) {
			int target = x - a[i].f - a[j].f;
			int k = j + 1, l = n - 1;
			while (k < l) {
				if (a[k].f + a[l].f == target )
				{
					cout << a[i].s + 1 << " " << a[j].s + 1 << " " << a[k].s + 1 << " " << a[l].s + 1;
					flag = false;
					break;
				}
				else if (a[k].f + a[l].f > target) l--;
				else k++;
			}
		}
	}
	if (flag) cout << "IMPOSSIBLE";
	return 0;
}