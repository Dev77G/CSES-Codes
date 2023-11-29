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
#define TIME            cout<<"\nTime in secs: "<< (float)clock() / CLOCKS_PER_SEC;

void JUDGE() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	JUDGE();
	// FAST
	get(t);
	while (t--) {
		getl(n); getl(k);
		ll cnt = 2 , n1 = n , i = 0;
		if (k <= n / 2) {
			cout << 2 * k << endl;
			continue;
		}
		while ( (i + (cnt * k) ) >  n ) {
			cnt *= 2;
			if ( n1 & 1) i = 1;
			else i = 0;

			k -= (n1 / 2);
			n1 -=  (n1 / 2);

			if (k == 1) {
				cout << i + 1 << endl;
				break;
			}

			if ((i + cnt * k ) >  n) {
				// cout << "K " << k << endl;
				cout << i + cnt * k << endl;
				break;
			}
		}

	}	TIME;
	return 0;
}