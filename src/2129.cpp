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

void hungarian(const vector<vector<long long>> &adj) {
    int n = (int) adj.size(), m = (int) adj[0].size();
    vector<long long> u(n), v(m);
    vector<int> match(m);
    for (int i = 1; i < n; i++) {
        int w = 0;
        match[w] = i;
        vector<long long> dist(m, LLONG_MAX);
        vector<int> pred(m, -1);
        vector<bool> vis(m);
        while (match[w]) {
            vis[w] = true;
            int cur = match[w], nw = 0;
            long long delta = LLONG_MAX;
            for (int j = 1; j < m; j++)
                if (!vis[j]) {
                    long long edge = adj[cur][j] - u[cur] - v[j];
                    if (edge < dist[j]) {
                        dist[j] = edge;
                        pred[j] = w;
                    }
                    if (dist[j] < delta) {
                        delta = dist[j];
                        nw = j;
                    }
                }
            for (int j=0; j<m; j++) {
                if (vis[j]) {
                    u[match[j]] += delta;
                    v[j] -= delta;
                } else {
                    dist[j] -= delta;
                }
            }
            w = nw;
        }
        while (w) {
            int nw = pred[w];
            match[w] = match[nw];
            w = nw;
        }
    }
    cout << -v[0] << "\n";
    for (int i = 1; i < n; i++) {
        cout << match[i] << " " << i << "\n";
    }
}

// Bipartite Matching -> min cost
 
void solve(int tc = 0) {
    int n; cin >> n;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
    hungarian(adj);
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