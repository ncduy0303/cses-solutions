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
const int MAX_L = 20;
const int MAX_C = 26;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int n, m, deg[MAX_N], pos[MAX_N], vis[MAX_N];
vector<pair<int,int>> adj[MAX_N];
 
vector<int> eulerPath(int s) {
    memset(deg, 0, sizeof deg);
    memset(pos, 0, sizeof pos);
    memset(vis, 0, sizeof vis);
 
    vector<int> ret;
    stack<int> st;
    st.push(s);
    deg[s]++;    // comment out to find tour instead of path
    while (!st.empty()) {
        int u = st.top();
        if (pos[u] == (int) adj[u].size()) {
            ret.push_back(u);
            st.pop();
            continue;
        }
 
        auto e = adj[u][pos[u]++];
        if (!vis[e.second]) {
            st.push(e.first);
            deg[u]--;
            deg[e.first]++;
            vis[e.second] = true;
        }
    }
 
    for (int i = 0; i < n; i++)
        if (deg[i] < 0 || (int) ret.size() < m + 1)
            return {};
    return {ret.rbegin(), ret.rend()};
}
 
void solve(int tc = 0) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back({v, i});
    }
    auto ans = eulerPath(0);
    if (ans.empty() || ans.back() != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int x : ans) cout << x + 1 << " ";
        cout << "\n";
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