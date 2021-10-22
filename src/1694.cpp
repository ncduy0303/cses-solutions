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

#define ar array
#define ll long long
#define ld long double
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
    long long cap, flow;
 
    Edge(int _u, int _v, long long _cap) : u(_u), v(_v), cap(_cap), flow(0) {}
};
 
struct Dinic {
    int m, s, t;
    vector<int> level, ptr;
    vector<Edge> edges;
    vector<vector<int>> adj;
 
    Dinic(int n, int _s, int _t) : m(0), s(_s), t(_t), level(n), ptr(n), adj(n) {}
 
    void addEdge(int u, int v, long long cap, long long rcap = 0) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, rcap);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }
 
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int e : adj[u])
                if (edges[e].flow < edges[e].cap && level[edges[e].v] == -1) {
                    level[edges[e].v] = level[u] + 1;
                    q.push(edges[e].v);
                }
        }
        return level[t] != -1;
    }
 
    long long dfs(int u, long long f) {
        if (f == 0 || u == t)
            return f;
        while (ptr[u] < (int) adj[u].size()) {
            int e = adj[u][ptr[u]], v = edges[e].v;
            long long nf;
            if (level[u] + 1 == level[v] && edges[e].flow < edges[e].cap && (nf = dfs(v, min(f, edges[e].cap - edges[e].flow))) > 0) {
                edges[e].flow += nf;
                edges[e^1].flow -= nf;
                return nf;
            }
            ptr[u]++;
        }
        return 0;
    }
 
    long long maxFlow(long long limit = LLONG_MAX) {
        long long ret = 0;
        while (limit > 0 && bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long f = dfs(s, limit)) {
                ret += f;
                limit -= f;
            }
        }
        return ret;
    }
};
 
void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    Dinic dn(n, 0, n - 1);
    while (m--) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        dn.addEdge(u, v, w);
    } 
    cout << dn.maxFlow() << "\n";
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