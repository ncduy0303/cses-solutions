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

struct SegmentTree {
    int n; vector<int> st;
    
    void init(int _n) { n = _n; st.resize(2 * _n); }
    void init(const vector<int> &a) {
        init(sz(a));
        for (int i = 0; i < n; i++) st[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) st[i] = max(st[i << 1], st[i << 1 | 1]);
    }
 
    int query(int l, int r) {
        int res = INT_MIN;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, st[l++]);
            if (r & 1) res = max(res, st[--r]);
        }
        return res;
    }
 
    void update(int i, int x) {
        for (st[i += n] = x; i > 1; i >>= 1) st[i >> 1] = max(st[i], st[i ^ 1]);
    }
};
 
template<bool VALS_IN_EDGE = false> struct HLD { 
    int n, ti;
    vector<vector<int>> adj;
    vector<int> par, tin, head, dep, sza;
    SegmentTree st;
    
    HLD(int _n) : n(_n), ti(0), adj(_n), par(_n), tin(_n), head(_n), dep(_n), sza(_n) { st.init(_n); }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfsSz(int u) {
        sza[u] = 1;
        for (int &v : adj[u]) {
            adj[v].erase(find(all(adj[v]), u)); // remove parent
            par[v] = u; dep[v] = dep[u] + 1;
            dfsSz(v);
            sza[u] += sza[v];
            if (sza[v] > sza[adj[u][0]]) swap(v, adj[u][0]); // store the heavy node at the beginning
        }
    }
    
    void dfsHld(int u) {
        tin[u] = ti++;
        for (int v : adj[u]) {
            head[v] = (v == adj[u][0] ? head[u] : v);
            dfsHld(v);
        }
    }
    
    void init(int s = 0) {
        par[s] = dep[s] = ti = 0; head[s] = s;
        dfsSz(s); dfsHld(s);
    }
    
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            v = par[head[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    template<class OP> void processPath(int u, int v, OP op) {
        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]]) swap(u, v);
            op(tin[head[u]], tin[u]);
            u = par[head[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        op(tin[u] + VALS_IN_EDGE, tin[v]);
    }
 
    void updateNode(int u, int x) { st.update(tin[u], x); }
    
    int queryPath(int u, int v) {
        int res = INT_MIN;
        processPath(u, v, [this, &res](int l, int r) { res = max(res, st.query(l, r + 1)); });
        return res;
    }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        hld.addEdge(u, v);
    }
    hld.init(0);
    for (int i = 0; i < n; i++) hld.updateNode(i, a[i]);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, x; cin >> u >> x; u--;
            hld.updateNode(u, x);
        } else {
            int u, v; cin >> u >> v; u--; v--;
            cout << hld.queryPath(u, v) << "\n";
        }
    }
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