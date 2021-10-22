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
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<vector<ar<int,2>>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        queries[r].push_back({l, i});
    }
    FenwickTree<ll> ft; ft.init(n);
    map<int,int> mp;
    vector<int> ans(q);
    for (int r = 0; r < n; r++) {
        if (mp.count(a[r])) ft.update(mp[a[r]], -1);
        mp[a[r]] = r;
        ft.update(r, 1);
        for (auto [l, i] : queries[r]) {
            ans[i] = ft.query(l, r);
        }
    }
    for (int x : ans) cout << x << "\n";
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