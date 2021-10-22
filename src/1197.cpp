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

const int MAX_N = 2.5e3 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, m, pre[MAX_N];
vector<ar<int,2>> adj[MAX_N];
ll dist[MAX_N];
 
bool bellmanFord(int s) {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0; pre[s] = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pre[v] = u;
                }
            }
        }
    }
    for (int u = 0; u < n; u++) 
        for (auto [v, w] : adj[u]) 
            if (dist[v] > dist[u] + w) 
                return true;
    return false;
}
 
vector<int> getCycle() {
    int node = -1;
    for (int u = 0; u < n; u++) 
        for (auto [v, w] : adj[u]) 
            if (dist[v] > dist[u] + w) 
                node = v;
    for (int i = 0; i < n; i++) node = pre[node];
    vector<int> cycle; cycle.push_back(node);
    for (int i = pre[node]; i != node; i = pre[i]) cycle.push_back(i); 
    cycle.push_back(node);
    reverse(cycle.begin(), cycle.end());
    return cycle;
}
 
void solve(int tc = 0) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].push_back({v, w});
    }
    if (bellmanFord(0)) {
        cout << "YES\n";
        auto ans = getCycle();
        for (int x : ans) cout << x + 1 << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
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