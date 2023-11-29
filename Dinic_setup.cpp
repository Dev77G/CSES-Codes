#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define get(a)          int a; cin>>a
#define getl(a)         long long a; cin>>a
#define put(a)          cout<<a<<" "
#define putn(a)         cout<<a<<"\n"
#define rep(i,a,b)      for(int i=a; i<=b; ++i)
#define vi              vector< int >
#define vl              vector< ll >
#define ump             unordered_map
#define pq_max          priority_queue< ll >
#define pq_min          priority_queue< ll , vl , greater<ll> >
#define reset(a, b)     memset(a, b, sizeof(a))
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vipii           vector<pair<int,pii>>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define pb              emplace_back
#define endl            "\n"
#define FAST            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TIME            cout<<"\nTime in secs: "<< (float)clock() / CLOCKS_PER_SEC;
const int mod = 1000000007;
const int N = 100001;
struct Edge {
	int v;
	int flow;
	int C;
	int rev;
};

class Graph {
	int V;
	int* level;
	vector<Edge>* adj;

public:
	Graph(int V)
	{
		adj = new vector<Edge>[V];
		this->V = V;
		level = new int[V];
	}
	void addEdge(int u, int v, int C)
	{
		Edge a{ v, 0, C, (int)adj[v].size() };
		Edge b{ u, 0, 0, (int)adj[u].size() };
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, int ptr[]);
	int DinicMaxflow(int s, int t);
};
bool Graph::BFS(int s, int t)
{
	for (int i = 0; i < V; i++)
		level[i] = -1;
	level[s] = 0;
	list<int> q;
	q.push_back(s);
	vector<Edge>::iterator i;
	while (!q.empty()) {
		int u = q.front();
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
int Graph::sendFlow(int u, int flow, int t, int start[])
{
	if (u == t)
		return flow;
	for (; start[u] < adj[u].size(); start[u]++) {
		Edge& e = adj[u][start[u]];
		if (level[e.v] == level[u] + 1 && e.flow < e.C) {
			int curr_flow = min(flow, e.C - e.flow);
			int temp_flow = sendFlow(e.v, curr_flow, t, start);
			if (temp_flow > 0) {
				e.flow += temp_flow;
				adj[e.v][e.rev].flow -= temp_flow;
				return temp_flow;
			}
		}
	}
	return 0;
}
int Graph::DinicMaxflow(int s, int t)
{
	if (s == t)
		return -1;

	int total = 0;
	while (BFS(s, t) == true) {
		int* start = new int[V + 1] { 0 };
		while (int flow = sendFlow(s, INT_MAX, t, start)) {
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
	rep(i, 0, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	cout << g.DinicMaxflow(0, n - 1);
	return 0;
}
