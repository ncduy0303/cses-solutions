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

struct SCC {
    int n, ti;
    vector<int> num, id, stk;
    vector<vector<int>> adj, dag, comp;
 
    SCC(int _n) : n(_n), ti(0), num(n), id(n, -1), adj(n) {}
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void init() {
        for (int u = 0; u < n; u++)
            if (!num[u])
                dfs(u);
        dag.resize(comp.size());
        for (auto &c : comp)
            for (int u : c)
                for (int v : adj[u])
                    if (id[u] != id[v])
                        dag[id[u]].push_back(id[v]);
        for (auto &v : dag) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    }
 
    int dfs(int u) {
        int low = num[u] = ++ti;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!num[v])
                low = min(low, dfs(v));
            else if (id[v] == -1)
                low = min(low, num[v]);
        }
        if (low == num[u]) {
            comp.emplace_back();
            do {
                id[stk.back()] = (int) comp.size() - 1;
                comp.back().push_back(stk.back());
                stk.pop_back();
            } while (comp.back().back() != u);
        }
        return low;
    }
};
 
struct TwoSat {
    int n;
    vector<int> ans;
    vector<pair<int, int>> edges;
 
    TwoSat(int _n = 0) : n(_n) {}
 
    int addVar() {
        return n++;
    }
 
    void addOr(int x, int y) {
        x = max(2 * x, -2 * x - 1), y = max(2 * y, -2 * y - 1);
        edges.emplace_back(x, y);
    }
 
    void addXor(int x, int y) {
        addOr(x, y);
        addOr(~x, ~y);
    }
 
    void addNand(int x, int y) {
        addOr(~x, ~y);
    }
 
    void equals(int x, int y) {
        addOr(~x, y);
        addOr(x, ~y);
    }
 
    void implies(int x, int y) {
        addOr(~x, y);
    }
 
    void set(int x) {
        addOr(x, x);
    }
 
    void atMostOne(const vector<int> &v) {
        if (v.size() <= 1)
            return;
        int cur = ~v[0];
        for (int i = 1; i < (int) v.size() - 1; i++) {
            int nxt = addVar();
            addOr(cur, ~v[i]);
            addOr(cur, nxt);
            addOr(~v[i], nxt);
            cur = ~nxt;
        }
        addOr(cur, ~v.back());
    }
 
    bool solve() {
        SCC scc(2 * n);
        for (auto &e : edges) {
            scc.addEdge(e.first ^ 1, e.second);
            scc.addEdge(e.second ^ 1, e.first);
        }
        scc.init();
        for (int u = 0; u < 2 * n; u += 2)
            if (scc.id[u] == scc.id[u + 1])
                return false;
        ans.assign(n, -1);
        for (auto &c : scc.comp)
            for (int u : c)
                if (ans[u / 2] == -1)
                    ans[u / 2] = u % 2 == 0;
        return true;
    }
};
 
void solve(int tc = 0) {
    int n, q; cin >> q >> n;
    TwoSat ts(n);
    while (q--) {
        char c1, c2; int x1, x2; cin >> c1 >> x1 >> c2 >> x2; x1--; x2--;
        if (c1 == '-') x1 = ~x1;
        if (c2 == '-') x2 = ~x2;
        ts.addOr(x1, x2);
    }
    if (ts.solve()) {
        for (int x : ts.ans) cout << (x ? '+' : '-') << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
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