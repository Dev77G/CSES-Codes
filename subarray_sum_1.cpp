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
	get(n);
	get(target);
	vi a(n);
	rep(i, 0, n - 1)
	cin >> a[i];
	int i = 0, j = 0, sum = 0, cnt = 0;
	while (j != n) {
		sum += a[j];
		if (sum == target) cnt++;
		while (sum > target)
		{
			sum -= a[i];
			if (sum == target) cnt++;
			i++;
		}
		j++;
	}
	cout << cnt;
	return 0;
}