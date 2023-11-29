#include <bits/stdc++.h>
#define get(a)          int a; cin>>a
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TIME            cout<<"\nTime in secs: "<< (float)clock() / CLOCKS_PER_SEC;

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
	get(n);
	set<int>s;
	for (int i = 0 ; i < n; ++i) {
		get(x);
		s.insert(x);
	}
	cout << s.size();
//	TIME
	return 0;
}