#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

// Edmonds_Karp template
struct max_flow_graph {
	int V;
	struct edge {
		int src, dst, cap, res;
		size_t rev;
	};
	edge &rev(edge e) { 
        return adj[e.dst][e.rev]; 
    };
	vector<vector<edge>> adj;
	max_flow_graph(int V) : V(V), adj(V) {}
	void add_edge(int src, int dst, int cap) {
		adj[src].push_back({src, dst, cap, 0, adj[dst].size()});   // original edge
		adj[dst].push_back({dst, src, 0, 0, adj[src].size() - 1}); // residual back edge (notice cap = 0)
	}
	ll max_flow(int s, int t) {
		for (int u = 0; u < V; u++)
			for (auto &e : adj[u])
                e.res = e.cap;
		ll total = 0;
		while (true) {
			vector<int> prev(V, -1); prev[s] = -2;
			queue<int> q; q.push(s);
			while (!q.empty() && prev[t] == -1) {
				int u = q.front(); q.pop();
				for (edge &e : adj[u]) {
					if (prev[e.dst] == -1 && e.res > 0) {
						prev[e.dst] = e.rev;
						q.push(e.dst);
					}
				}
			}
			if (prev[t] == -1) break;
			int inc = INF;
			for (int u = t; u != s; u = adj[u][prev[u]].dst)
				inc = min(inc, rev(adj[u][prev[u]]).res);
			for (int u = t; u != s; u = adj[u][prev[u]].dst) {
				adj[u][prev[u]].res += inc;
				rev(adj[u][prev[u]]).res -= inc;
			}
			total += inc;
		}
		return total;
	}
};

void solve() {
    int n, m; cin >> n >> m;
    max_flow_graph adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj.add_edge(u, v, w);
    }
    cout << adj.max_flow(0, n - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
