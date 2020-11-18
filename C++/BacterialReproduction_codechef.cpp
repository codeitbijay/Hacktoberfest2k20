/* Louis Pasteur has a rooted tree with N vertices (numbered 1 through N); vertex 1 is the root of the tree. Initially, there are some bacteria in its vertices. Let's denote the number of sons of vertex v by sv; a leaf is a vertex without sons. During each second, the following events happen:

For each non-leaf vertex v, if there are x bacteria in this vertex at the start of this second, they divide into sv⋅x bacteria. At the end of this second, x of these bacteria instantly move to each of its sons (none of them stay in vertex v). The original x bacteria do not exist any more.
Zero or more bacteria appear in one vertex. These bacteria do not divide or move at this second.
Initially, we are at the start of second 0. You should process Q queries ― one query during each of the seconds 0 through Q−1. There are two types of queries:

+ v k: During this second, k bacteria appear in vertex v.
? v: Find the number of bacteria in vertex v at the end of this second ― after the divided bacteria have moved.
*/

/*Input :
The first line of the input contains two space-separated integers N and Q.
Each of the next N−1 lines contains two space-separated integers x and y denoting that vertices x and y are connected by an edge.
The next line contains N space-separated integers a1,a2,…,aN denoting the initial numbers of bacteria in vertices 1 through N.
Q lines follow. Each of these lines describes a query in the format + v k or ? v.
*/

//Solution:

#include <bits/stdc++.h>
using namespace std;
using ll = long long; const int N = 5e5, Q = N;

template <class T, class G> 
class segment_tree {
	vector<T> t; const int n; const G combine; 
public:
	segment_tree(int N) : t(N << 1,0), n(N), combine(G()) {}
	inline void set(int i, T b) {
		for (t[i += n] = b; i > 1; i >>= 1) 
			 t[i>>1] = combine(t[i],t[i^1]); }
	inline void add(int i, T delta) { set(i,combine(t[n+i],delta)); }
	inline T query(int l, int r) const { 
		T ans = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    		if (l&1) ans = combine(ans,t[l++]); 
    		if (r&1) ans = combine(ans,t[--r]); } return ans; }
    inline T operator[](int i) const { return t[n+i]; } };

segment_tree<ll,plus<ll>> bacteria(N+Q); ll ans[Q];

struct vertex
{
	int a, ap; vector<int> children, query; vector<pair<int,int>> appears; 
	
	bool leaf, proc;
	
	vertex() : a(0), ap(0), leaf(false), proc(false) {}
	
	inline void add_edge(int x)
	{
		children.push_back(x);
	}

	inline void read_a()
	{
		cin >> a;
	}
	
	inline void add_appearance(int time)
	{
		int k; cin >> k, appears.emplace_back(time,k);
	}
	
	inline void add_query(int time)
	{
		query.push_back(time);
	}
	
	inline void erase_ancestor(int p, int q)
	{
    	const auto it = children.begin(), iu = children.end();

    	sort(it,iu), children.erase(lower_bound(it,iu,p)), 
    	leaf = children.empty(), ap = q;
	}
	
	inline void preprocess()
	{
		proc = not query.empty();
	}
	
	inline void add(int i)
	{
		const int j = N-i;
		
		if (i)
			bacteria.add(j,ap);
	
		for (auto z: appears)
			bacteria.add(j+z.first,z.second);
		
		if (leaf)
			bacteria.add(j,a);
	}
	
	inline void sub(int i)
	{
		const int j = N-i;
		
		if (i)
			bacteria.add(j,-ap);
	
		for (auto z: appears)
			bacteria.add(j+z.first,-z.second);
		
		if (leaf)
			bacteria.add(j,-a);
	}
	
	inline void solve(int i)
	{
		for (auto time: query)
		{	
			int  k = N+time-i; 
		
			if (leaf)
				ans[time] = bacteria.query(0,k+1);
			else  
				ans[time] = bacteria[k];
		}
	}
};

struct rooted_tree: vector<vertex>
{
	void read_edge()
	{
		int x, y; cin >> x >> y, at(x).add_edge(y), at(y).add_edge(x);
	}
	
	void erase_ancestors(int p, int u)
	{
    	at(u).erase_ancestor(p,at(p).a);

    	for (auto v: at(u).children)
        	erase_ancestors(u,v);
	}
	
	bool preprocess(int u)
	{
		at(u).preprocess();
	
    	for (auto v: at(u).children)
        	if (preprocess(v))
            	at(u).proc = true;

    	return at(u).proc;
	}
	
	void solve(int i, int u)
	{
		if (at(u).add(i), at(u).solve(i), not at(u).leaf)
		{
			++i; for (auto v: at(u).children) if (at(v).proc) solve(i,v); --i;
		}
	
		at(u).sub(i);
	}

	rooted_tree(int n)
	{
		const int p = n+1; resize(p);

		for (int i = 1; i < n; ++i)
        	read_edge();

    	for (int u = 1; u < p; ++u)
    		at(u).read_a();
	}
};

int main()
{
	int n, q; char t; vector<int> query_time; const int root = 1;
	
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr),
	cin >> n >> q; rooted_tree g(n); g[root].add_edge(0);
	
	for (int v, k, time = 0; time < q; ++time)
		if (cin >> t >> v, t == '+')
			g[v].add_appearance(time);
        else
            query_time.push_back(time), g[v].add_query(time);

	if (g.erase_ancestors(0,root), not g.preprocess(root))
        exit(0);

	g.solve(0,root);
	
	for (auto time: query_time)
        cout << ans[time] << '\n';
}
