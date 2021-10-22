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

template<typename T> struct FenwickTree2D {
    int n, m; vector<vector<T>> ft;
    
    void init(int _n, int _m) { n = _n; m = _m; ft.resize(_n + 1, vector<T>(_m + 1)); }

    void update(int x, int y, T v) {
        for (int tx = x; tx <= n; tx += tx&-tx)
            for (int ty = y; ty <= m; ty += ty&-ty)
                ft[tx][ty] += v;
    }

    T query(int x, int y) {
        T res = 0;
        for (int tx = x; tx; tx -= tx&-tx) 
            for (int ty = y; ty; ty -= ty&-ty)
                res += ft[tx][ty];
        return res;
    }
    T query(int x1, int y1, int x2, int y2) { return (x1 <= x2 && y1 <= y2) ? query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) : 0; }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    FenwickTree2D<ll> ft; ft.init(n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == '*') ft.update(i, j, 1);
        }
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, j; cin >> i >> j;
            ft.update(i, j, (ft.query(i, j, i, j) ? -1 : 1));
        } else {
            int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
            cout << ft.query(i1, j1, i2, j2) << "\n";
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