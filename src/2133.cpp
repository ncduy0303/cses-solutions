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

struct DSU {
    int num; vector<int> par, sza, stk;
    void init(int _n) {
        num = _n;
        par = vector<int>(_n); iota(par.begin(), par.end(), 0);
        sza = vector<int>(_n, 1);
        stk.clear();
    }
    int find(int u) { return u == par[u] ? u : find(par[u]); }
    bool same(int u, int v) { return find(u) == find(v); }
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sza[u] > sza[v]) swap(u, v);
        par[u] = v;
        sza[v] += sza[u];
        num--;
        stk.push_back(u);
        return true;
    }
    void undo(int t) {
        while ((int) stk.size() > t) {
            int u = stk.back();
            stk.pop_back();
            num++;
            sza[par[u]] -= sza[u];
            par[u] = u;
        }
    }
};
 
int ln(int node) { return 2 * node; }
int rn(int node) { return 2 * node + 1; }
 
int n, m, q, ans[MAX_N];
vector<ar<int,2>> st[4 * MAX_N];
DSU dsu;
 
void update(int node, int start, int end, int l, int r, ar<int,2> e) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        st[node].push_back(e);
        return;
    }
    int mid = (start + end) / 2;
    update(ln(node), start, mid, l, r, e);
    update(rn(node), mid + 1, end, l, r, e);
}
 
void calc(int node, int start, int end) {
    int t = sz(dsu.stk);
    for (auto [u, v] : st[node]) dsu.merge(u, v);
    if (start == end) {
        ans[start] = dsu.num;
    } else {
        int mid = (start + end) / 2;
        calc(ln(node), start, mid);
        calc(rn(node), mid + 1, end);
    }
    dsu.undo(t);
}

// Dynamic Connectivity Offline
 
void solve(int tc = 0) {
    cin >> n >> m >> q;
    dsu.init(n);
    map<ar<int,2>,int> mp;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u > v) swap(u, v);
        mp[{u, v}] = 0;
    }
    for (int i = 1; i <= q; i++) {
        int t, u, v; cin >> t >> u >> v; u--; v--;
        if (u > v) swap(u, v);
        if (t == 1) {
            mp[{u, v}] = i;
        } else {
            update(1, 0, q, mp[{u, v}], i - 1, {u, v});
            mp.erase({u, v});
        }
    }
    for (auto [e, i] : mp) update(1, 0, q, i, q, e);
    calc(1, 0, q);
    for (int i = 0; i <= q; i++) cout << ans[i] << " ";
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