#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll              long long
#define ld              long double
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define put(a)          cout<<a<<" "
#define putn(a)         cout<<a<<"\n"
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define repr(i,a,b)     for(int i=a; i>=b; --i)
#define vi              vector<int>
#define vl              vector<long long>
#define vs              vector<string>
#define ump             unordered_map
#define pq_max          priority_queue<long long>
#define pq_min          priority_queue< long long , vl , greater<long long> >
#define reset(a, b)     memset(a, b, sizeof(a))
#define init(a,n)       vector<long long> a(n+1); for(int i=1; i<=n; i++) { cin>>a[i]; }
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n";
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mod             1000000007
#define N               100001
#define pb              emplace_back
#define pf              first
#define ps              second
#define bpc             __builtin_popcountll
#define clz             __builtin_clzll
#define ctz             __builtin_ctzll
#define precise(n)      cout<<fixed<<setprecision(n)

using namespace std;
// using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

void make(int i, vector<int>&par ) {
    par[i] = i;
}

int find(int i, vector<int>&par ) {
    if (par[i] == i)   return i;
    return par[i] = find(par[i], par);
}

void Union(int u, int v, vector<int>&par ) {
    u = find(u, par);
    v = find(v, par);
    if (u != v)
        par[v] = u;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll ans = 0;
    int n , m ;
    cin >> n >> m;
    vector<int>par(n, 0), mst_cost(n, 0);

    vector<pair<int, pair<int, int>>>g;
    for (int i = 0; i < n; i++)
        make(i, par);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x > y) swap(x, y);
        pair<int, pair<int, int>>p = {z, {x, y}};
        g.pb(p);
    }
    sort(g.begin(), g.end());
    cout << dd;

    for (auto p : g) {
        int u = p.second.first;
        int v = p.second.second;
        if (find(u, par) == find(v, par)) continue;

        mst_cost[u] += p.first;
        Union(u, v, par);
    }

    for (int i = 0; i < n; i++) {
        if ( mst_cost[i] != 0  && par[i] != i ) {
            int p = find(i, par);
            mst_cost[p] += mst_cost[i];
        }
    }

    cout << *max_element(all(mst_cost));
    return 0;
}