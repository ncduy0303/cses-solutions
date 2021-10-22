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

const int MAX_N = 2e5 + 5;
const int MAX_L = 30;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, q, par[MAX_N][MAX_L], dep[MAX_N], cy[MAX_N];
 
void dfs(int u, int d = 0) {
    cy[u] = --d;
    int v = par[u][0];
    if (cy[v] == 0) {
        dfs(v, d);
    }
    if (cy[v] < 0) {
        cy[u] = cy[v] - cy[u] + 1;
        dep[u] = 0;
    } else {
        cy[u] = cy[v];
        dep[u] = dep[v] + 1;
    }
}
 
int kthAnc(int u, int k) {
    for (int i = 0; i < MAX_L; i++) 
        if (k & (1 << i)) 
            u = par[u][i];
    return u;
}
 
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = kthAnc(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = MAX_L - 1; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}
 
void solve(int tc = 0) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> par[i][0];
    for (int i = 1; i < MAX_L; i++)
        for (int u = 1; u <= n; u++)
            par[u][i] = par[par[u][i - 1]][i - 1];
    for (int i = 1; i <= n; i++) {
        if (cy[i] == 0) {
            dfs(i);
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        if (dep[u] >= dep[v] && kthAnc(u, dep[u] - dep[v]) == v) {
            cout << dep[u] - dep[v] << "\n";
        } else if (dep[u] + cy[u] >= dep[v] && kthAnc(u, dep[u] + cy[u] - dep[v]) == v) {
            cout << dep[u] + cy[u] - dep[v] << "\n";
        } else {
            cout << -1 << "\n";
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