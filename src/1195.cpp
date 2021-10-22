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

int n, m;
vector<ar<int,2>> adj[2][MAX_N];
ll dist[2][MAX_N];
 
void dijkstra(int t, int s) {
    priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
    pq.push({dist[t][s] = 0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[t][u]) continue;
        for (auto [v, w] : adj[t][u]) {
            if (dist[t][v] > dist[t][u] + w) {
                dist[t][v] = dist[t][u] + w;
                pq.push({dist[t][v], v});
            }
        }
    } 
}
 
void solve(int tc = 0) {
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    vector<ar<int,3>> el(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[0][u].push_back({v, w});
        adj[1][v].push_back({u, w});
        el[i] = {u, v, w};
    }
    dijkstra(0, 0);
    dijkstra(1, n - 1);
    ll ans = LLONG_MAX;
    for (auto [u, v, w] : el) {
        ans = min(ans, dist[0][u] + dist[1][v] + w / 2);
    }
    cout << ans << "\n";
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