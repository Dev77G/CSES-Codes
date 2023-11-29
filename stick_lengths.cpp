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
	vi a(n);
	rep(i, 0, n - 1)
	cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0 , k =  a[n / 2];
	rep(i, 0, n - 1) sum += abs(a[i] - k);
	if (n % 2 == 0) {
		ll sum1 = 0;
		k--;
		rep(i, 0, n - 1) sum1 += abs(a[i] - k);
		sum = min(sum, sum1);
	}
	cout << sum;
	return 0;
}