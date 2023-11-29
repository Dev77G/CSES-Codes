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

void dfs(int i, int j, int &n, int &m, vector<string>&a) {
	if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '#') return ;
	a[i][j] = '#' ;
	dfs(i + 1, j, n, m, a);
	dfs(i - 1, j, n, m, a);
	dfs(i, j + 1, n, m, a);
	dfs(i, j - 1, n, m, a);
}
int main()
{
	JUDGE();
	FAST
	get(n);
	get(m);
	int cnt = 0;
	vector<string> a(n);
	rep(i, 0, n - 1)
	cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == '.')
			{
				cnt++;
				dfs(i, j, n, m, a);
			}
	cout << cnt;
	return 0;
}