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

struct BinaryLift {
    int n, lg;
    vector<int> dep, cnt;
    vector<vector<int>> adj, par;
    
    BinaryLift(int _n) : n(_n), lg(__lg(n - 1) + 1), dep(n), cnt(n), adj(n), par(n, vector<int>(lg, -1)) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    void init(int s = 0) {
        dfs(s);
        for (int j = 1; j < lg; j++) {
            for (int i = 0; i < n; i++) {
                if (par[i][j - 1] != -1) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }
        }
    }
 
    void dfs(int u) {
        for (int v : adj[u]) {
            if (v == par[u][0]) continue;
            dep[v] = dep[u] + 1;
            par[v][0] = u;
            dfs(v);
        }
    }
 
    int kthAnc(int u, int k) {
        if (k > dep[u]) return -2;
        for (int j = 0; j < lg; j++) {
            if (k & (1 << j)) {
                u = par[u][j];
            }
        }
        return u;
    }
 
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = kthAnc(u, dep[u] - dep[v]);
        if (u == v) return u;
        for (int j = lg - 1; j >= 0; j--) {
            if (par[u][j] != par[v][j]) {
                u = par[u][j];
                v = par[v][j];
            }
        }
        return par[u][0];
    }
 
    int dist(int u, int v) { 
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
 
    void addPath(int u, int v) {
        int m = lca(u, v);
        cnt[u]++; cnt[v]++; cnt[m]--;
        if (par[m][0] != -1) cnt[par[m][0]]--;
    }
 
    void dfsPath(int u, int p = -1) {
        for (int v : adj[u]) {
            if (v == p) continue;
            dfsPath(v, u);
            cnt[u] += cnt[v];
        }
    }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    BinaryLift bl(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        bl.addEdge(u, v);
    }
    bl.init(0);
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        bl.addPath(u, v);
    }
    bl.dfsPath(0);
    for (int x : bl.cnt) cout << x << " ";
    cout << "\n";
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