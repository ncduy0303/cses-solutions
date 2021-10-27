#include <bits/stdc++.h>

using namespace std;

#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
template<typename A, typename B> print_op(pair<A, B>) { return out << "(" << u.first << ", " << u.second << ")"; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> print_op(T_container) { out << "{"; string sep; for (const T &x : u) out << sep << x, sep = ", "; return out << "}"; }
template<typename T> void dbg_out(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void dbg_out(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; dbg_out(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
#ifdef LOCAL
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;
using ld = long double;
#define ar array
#define sz(x) ((int)x.size())
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++) 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct Edge {
    int u, v;
    long long cap, cost, flow;
 
    Edge(int _u, int _v, long long _cap, long long _cost) : u(_u), v(_v), cap(_cap), cost(_cost), flow(0) {}
};
 
struct MCMF {
    int m, n, s, t;
    bool neg;
    vector<int> par;
    vector<long long> pi, dist;
    vector<Edge> edges;
    vector<vector<int>> adj;
 
    MCMF(int _n, int _s, int _t) : m(0), n(_n), s(_s), t(_t), neg(false), par(n), pi(n), dist(n), adj(n) {}
 
    void addEdge(int u, int v, long long cap, long long cost) {
        edges.emplace_back(u, v, cap, cost);
        edges.emplace_back(v, u, 0, -cost);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
        neg |= cost < 0;
    }
 
    bool path() {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(dist[s] = 0, s);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (int e : adj[u])
                if (edges[e].flow < edges[e].cap && dist[u] + edges[e].cost + pi[u] - pi[edges[e].v] < dist[edges[e].v]) {
                    par[edges[e].v] = e;
                    pq.emplace(dist[edges[e].v] = dist[u] + edges[e].cost + pi[u] - pi[edges[e].v], edges[e].v);
                }
        }
        return dist[t] < LLONG_MAX;
    }
 
    void setpi() {
        fill(pi.begin(), pi.end(), LLONG_MAX);
        pi[s] = 0;
        bool cycle;
        for (int i=0; i<n; i++) {
            cycle = false;
            for (const Edge &e : edges)
                if (e.cap > 0 && pi[e.u] < LLONG_MAX && pi[e.u] + e.cost < pi[e.v]) {
                    pi[e.v] = pi[e.u] + e.cost;
                    cycle = true;
                }
        }
        assert(!cycle);
    }
 
    pair<long long, long long> maxFlow(long long limit = LLONG_MAX) {
        if (neg)
            setpi();
        long long retFlow = 0, retCost = 0;
        while (limit > 0 && path()) {
            for (int u=0; u<n; u++)
                pi[u] += dist[u];
            long long f = limit;
            for (int u=t; u!=s; u=edges[par[u]].u)
                f = min(f, edges[par[u]].cap - edges[par[u]].flow);
            retFlow += f;
            retCost += f * (pi[t] - pi[s]);
            limit -= f;
            for (int u=t; u!=s; u=edges[par[u]].u) {
                edges[par[u]].flow += f;
                edges[par[u] ^ 1].flow -= f;
            }
        }
        return {retFlow, retCost};
    }
 
    void query(int k) {
        auto [mf, mc] = maxFlow(k);
        if (mf < k) {
            cout << -1 << "\n";
            return;
        }
        cout << mc << "\n";
        vector<bool> vis(m);
        vector<int> path;
 
        function<void(int)> dfsFlow = [&](int u) {
            path.push_back(u);
            if (u == t) return;
            for (int e : adj[u]) {
                if (e % 2) continue;
                auto &[_, v, cap, cost, flow] = edges[e];
                if (cap == flow && !vis[e]) {
                    flow = 0;
                    vis[e] = true;
                    dfsFlow(v);
                    return;
                }
            }
        };
 
        while (mf--) {
            dfsFlow(s);
            cout << sz(path) << "\n";
            for (int x : path) cout << x + 1 << " ";
            cout << "\n";
            path.clear();
        }
    }
};

// MCMF -> print all the paths
 
void solve(int tc = 0) {
    int n, m, k; cin >> n >> m >> k;
    MCMF mcmf(n, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        mcmf.addEdge(u, v, 1, 1);
    }
    mcmf.query(k);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}