#include <bits/stdc++.h>

#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define putyes          cout<<"YES\n";
#define putno           cout<<"NO\n";
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
	get(t);
	int a, s, d, f, g, h;
	cin >> a >> s >> d >> f >> g >> h;
	ll maxi = min(a, g) + min(s, h) + min(d, f);
	ll mini = max(a - f - h , 0) + max(s - f - g , 0) + max(d - g - h , 0);
	cout << mini << " " << maxi;
	return 0;
}