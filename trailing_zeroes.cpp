#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define getl(a)         long long a; cin>>a
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
	getl(n);
	ll cnt = 0;
	while (n) {
		cnt += n / 5 ;
		n /= 5;
	}
	cout << cnt;
	return 0;
}