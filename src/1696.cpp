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

struct Matching {
    int n, m;
    vector<int> matchL, matchR, dist;
    vector<vector<int>> adj;
 
    Matching(int _n, int _m) : n(_n), m(_m), matchL(n + 1), matchR(m + 1), dist(n + 1), adj(n + 1) {}
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
 
    bool bfs() {
        queue<int> q;
        for (int u=1; u<=n; u++) {
            if (!matchL[u]) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        dist[0] = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist[0])
                for (int v : adj[u])
                    if (dist[matchR[v]] == INT_MAX) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
        }
        return dist[0] != INT_MAX;
    }
 
    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u])
                if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }
 
    int solve() {
        int ret = 0;
        while (bfs())
            for (int u=1; u<=n; u++)
                if (!matchL[u] && dfs(u))
                    ret++;
        return ret;
    }
};
 
void solve(int tc = 0) {
    int n, m, k; cin >> n >> m >> k;
    Matching mc(n, m);
    while (k--) {
        int u, v; cin >> u >> v;
        mc.addEdge(u, v);
    }
    cout << mc.solve() << "\n";
    for (int i = 1; i <= n; i++) {
        if (mc.matchL[i]) {
            cout << i << " " << mc.matchL[i] << "\n";
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