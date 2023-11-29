prime using sieve
kth small / largest in O(n)
manacher algo
Z algo
factorial
a^b % m
binary uplifting,
       bitmask techniques and builtin functions
       dfs, bfs, dsu, PnC

       2D ARRAY
       vector < vector<int >>t(5, vector<int>(5));
rep(i, 0, 3)
rep(j, 0, 2)
cout << t[i][j];

A + B = A ^ B + 2 ( A & B );
A + B = A | B +   ( A & B );


void factors(int x, unordered_map<int, int>&m ) {
	while (x % 2 == 0) {
		m[2]++;
		x /= 2;
	}
	for (int i = 3; i * i <= x; i += 2) {
		while (x % i == 0) {
			m[i]++;
			x /= i;
		}
	}
	if (x > 1) m[x]++;
}
#define bpc             __builtin_popcountll  //no of set bits
#define clz             __builtin_clzll		  //0's on left
#define ctz             __builtin_ctzll		  //0's on right

int binexp(int a, int b, int mod) {
	assert(b >= 0);
	a = a % mod;
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b /= 2;
	}
	return ans;
}

int inv(int a) {
	a %= mod;
	if (a < 0) a += mod;
	int b = mod, u = 0, v = 1;
	while (a) {
		int t = b / a;
		b -= t * a; swap(a, b);
		u -= t * v; swap(u, v);
	}
	assert(b == 1);
	if (u < 0) u += mod;
	return u;
}



struct DSU
{
	int n;
	vi parent;
	vi size1;
	DSU(int N)
	{
		n = N;
		parent.assign(n + 1, -1);
		size1.assign(n + 1, 1);
		for (int i = 0; i <= n; i++)parent[i] = i;
	}
	int find_set(int i)
	{
		if (parent[i] == i)return i;
		return parent[i] = find_set(parent[i]);
	}
	bool union_sets(int a, int b)
	{
		a = find_set(a);
		b = find_set(b);
		if (a == b) {
			return false;
		}
		if (a != b) {
			if (size1[a] < size1[b])
				swap(a, b);
			parent[b] = a;
			size1[a] += size1[b];
		}
		return true;
	}
};

int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

ll power(ll a, ll b, ll mod) {
	if (b == 0) {
		return 1;
	}
	ll ans = power(a, b / 2, mod);
	ans *= ans;
	ans %= mod;
	if (b % 2) {
		ans *= a;
	}
	return ans % mod;
}

vector<lol> primeFactors(lol n) {
	vector<lol> factors; lol d = 2; while (n > 1) {
		while (n % d == 0) {
			factors.push_back(d); n /= d;
		} d++;
		if (d * d > n) {if (n > 1) factors.push_back(n); break;}
	} return factors;
}


bool vis[N];
const int maxn = 2e7;
bitset < maxn + 5 > vis;
vector<int> prime;

void sieve() {
	for (lol i = 2; i < N; i++) {
		if (vis[i] == 0) {
			st.insert(i);
			for (lol j = i + i; j < N; j += i) {
				vis[j] = 1;
			}
		}
	}

}

void sieve() {
	for (int i = 2; i <= maxn; i++) {
		if (!vis[i]) {
			prime.push_back(i);
			if (1ll * i * i <= maxn) {
				for (int j = i * i; j <= maxn; j += i) {
					vis[j] = 1;
				}
			}
		}
	}
}
void sieve()
{
	is_prime[0] = is_prime[1] = true;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i] == false && i * i <= N)
		{
			for (int j = i * i; j <= N; j += i)
			{
				is_prime[j] = true;
			}
		}
	}
}


ll power(ll x, ll y, ll p) {
	ll res = 1; x = x % p; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;
}
ll modInverse(ll n, ll p) {
	return power(n, p - 2, p);
}
vector<ll> fac;
void factorial(int n, int MOD) {
	fac.resize(n + 1); fac[0] = 1; for (int i = 1; i < n; i++) {fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p) {
	if (n < r)return 0;
	if (r == 0)return 1;
	return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}
vector<ll> primes;
void seive(ll n) {
	bool prime[n + 1]; memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
	}
	for (int p = 2; p <= n; p++)if (prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
	if ( num < 2 ) { return 0;} ll cnt = 0;
	for ( auto x : primes ) {while ( num % x == 0 ) {cnt++; num /= x ;}}
	if ( num > 1) {cnt++;}
	return cnt;
}