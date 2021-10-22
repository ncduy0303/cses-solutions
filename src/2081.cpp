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

template<typename T> struct FenwickTree {
    int n; vector<T> ft;
    
    void init(int _n) { n = _n; ft.resize(_n); }
    void init(const vector<int> &a) { init(sz(a)); for (int i = 0; i < n; i++) update(i, a[i]); }

    void update(int x, T v) { for (; x < n; x = x | (x + 1)) ft[x] += v; }
    void update(int l, int r, T v) { update(l, v); update(r + 1, -v); }

    T query(int x) {
        T res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) res += ft[x];
        return res;
    }
    T query(int l, int r) { return (l <= r) ? query(r) - query(l - 1) : 0; }
};

struct CentroidDecomposition {
    vector<int> sza, par, vis;
    vector<vector<int>> adj;
    int l, r; ll ans;
    FenwickTree<ll> cnt;

    CentroidDecomposition(int n, int _l, int _r) : sza(n), par(n), vis(n), adj(n), l(_l), r(_r), ans(0) { cnt.init(r + 1); }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int u = 0, int p = -1) {
        u = centroid(u, p, dfsSz(u, p));
        par[u] = p;
        vis[u] = 1;
        cnt.update(0, 1);
        int mx = 0;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfsSolve(v, u, 1, true, mx);
                dfsSolve(v, u, 1, false, mx);
            }
        } 
        for (int i = 0; i <= mx; i++) cnt.update(i, -cnt.query(i, i));
        for (int v : adj[u])
            if (!vis[v])
                build(v, u);
    }

    void dfsSolve(int u, int p, int d, bool flag, int &mx) {
        if (d > r) return;
        mx = max(mx, d);
        if (flag) ans += cnt.query(max(0, l - d), r - d);
        else cnt.update(d, 1);
        for (int v : adj[u]) {
            if (vis[v] || v == p) continue;
            dfsSolve(v, u, d + 1, flag, mx);
        }
    }

    int dfsSz(int u, int p) {
        sza[u] = 1;
        for (int v : adj[u])
            if (v != p && !vis[v])
                sza[u] += dfsSz(v, u);
        return sza[u];
    }

    int centroid(int u, int p, int nn) {
        for (int v : adj[u])
            if (v != p && !vis[v] && sza[v] > nn / 2)
                return centroid(v, u, nn);
        return u;
    }

    int operator [] (int i) const {
        return par[i];
    }
};
 
void solve(int tc = 0) {
    int n, l, r; cin >> n >> l >> r;
    CentroidDecomposition cd(n, l, r);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        cd.addEdge(u, v);
    }
    cd.build();
    cout << cd.ans << "\n";
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