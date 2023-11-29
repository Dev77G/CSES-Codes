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
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	JUDGE();
	FAST
	get(n);
	ll a = 0 , b = 0 , s = ( n * (n + 1) ) / 2 ;
	if (s & 1)	   cout << "NO";
	else {
		cout << "YES" << endl;
		vector<int>a1, b1;
		for (int i = n; i >= 1; i--) {
			if (a < b) {
				a1.push_back(i);
				a += i;
			}
			else {
				b1.push_back(i);
				b += i;
			}
		}
		cout << a1.size() << endl;
		for (auto i : a1) cout << i << " ";
		cout << endl << b1.size() << endl;
		for (auto i : b1) cout << i << " ";
	}
	return 0;
}