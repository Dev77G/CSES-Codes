#include <bits/stdc++.h>
using namespace std;
#define get(a)          long long a; cin>>a
#define getl(a)         long long a; cin>>a
#define put(a)          cout<<a<<" "
#define putn(a)         cout<<a<<"\n"
#define rep(i,a,b)      for(long long i=a; i<=b; ++i)
#define vi              vector< long long >
#define vl              vector< ll >
#define ump             unordered_map
#define pq_max          priority_queue< ll >
#define pq_min          priority_queue< ll , vl , greater<ll> >
#define reset(a, b)     memset(a, b, sizeof(a))
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<long long,long long>
#define pll             pair<ll,ll>
#define vipii           vector<pair<long long,pii>>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define pb              emplace_back
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TIME            cout<<"\nTime in secs: "<< (float)clock() / CLOCKS_PER_SEC;
const long long mod = 1000000007;
const long long N = 100001;
struct Edge {
	long long v;
	long long flow;
	long long C;
	long long rev;
};

class Graph {
	long long V;
	long long* level;
	vector<Edge>* adj;

public:
	Graph(long long V)
	{
		adj = new vector<Edge>[V];
		this->V = V;
		level = new long long[V];
	}
	void addEdge(long long u, long long v, long long C)
	{
		Edge a{ v, 0, C, (long long)adj[v].size() };
		Edge b{ u, 0, 0, (long long)adj[u].size() };
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	bool BFS(long long s, long long t);
	long long sendFlow(long long s, long long flow, long long t, long long ptr[]);
	long long DinicMaxflow(long long s, long long t);
};
bool Graph::BFS(long long s, long long t)
{
	for (long long i = 0; i < V; i++)
		level[i] = -1;
	level[s] = 0;
	list<long long> q;
	q.push_back(s);
	vector<Edge>::iterator i;
	while (!q.empty()) {
		long long u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			Edge& e = *i;
			if (level[e.v] < 0 && e.flow < e.C) {
				level[e.v] = level[u] + 1;
				q.push_back(e.v);
			}
		}
	}

	return level[t] < 0 ? false : true;
}
long long Graph::sendFlow(long long u, long long flow, long long t, long long start[])
{
	if (u == t)
		return flow;
	for (; start[u] < adj[u].size(); start[u]++) {
		Edge& e = adj[u][start[u]];
		if (level[e.v] == level[u] + 1 && e.flow < e.C) {
			long long curr_flow = min(flow, e.C - e.flow);
			long long temp_flow = sendFlow(e.v, curr_flow, t, start);
			if (temp_flow > 0) {
				e.flow += temp_flow;
				adj[e.v][e.rev].flow -= temp_flow;
				return temp_flow;
			}
		}
	}
	return 0;
}
long long Graph::DinicMaxflow(long long s, long long t)
{
	if (s == t)
		return -1;

	long long total = 0;
	while (BFS(s, t) == true) {
		long long* start = new long long[V + 1] { 0 };
		while (long long flow = sendFlow(s, INT_MAX, t, start)) {
			total += flow;
		}
		delete[] start;
	}
	return total;
}
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
	get(n);				//no. of nodes
	get(m);				//no. of edges
	Graph g(n);			//indexing starts 0
	rep(i, 0, m - 1) {
		long long u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u - 1, v - 1, w);
	}
	cout << g.DinicMaxflow(0, n - 1);
	return 0;
}
