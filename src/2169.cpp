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

// exchange arguments

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

bool cmp1(const ar<int,3> &x, const ar<int,3> &y) {
    return (x[0] == y[0]) ? x[1] < y[1] : x[0] > y[0];
}
 
bool cmp2(const ar<int,3> &x, const ar<int,3> &y) {
    return (x[0] == y[0]) ? x[1] > y[1] : x[0] < y[0];
}
 
void solve(int tc = 0) {
    int n; cin >> n;
    vector<ar<int,3>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r, i};
        b.push_back(l);
        b.push_back(r);
    }
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    for (int i = 0; i < n; i++) {
        a[i][0] = lower_bound(all(b), a[i][0]) - b.begin();
        a[i][1] = lower_bound(all(b), a[i][1]) - b.begin();
    }
    vector<int> ans1(n), ans2(n);
    FenwickTree<ll> ft1, ft2; ft1.init(2 * n); ft2.init(2 * n);
    sort(all(a), cmp1);
    for (auto [l, r, i] : a) {
        ans1[i] = ft1.query(l, r);
        ft1.update(r, 1);
    }
    sort(all(a), cmp2);
    for (auto [l, r, i] : a) {
        ans2[i] = ft2.query(r, 2 * n - 1);
        ft2.update(r, 1);
    }
    for (int x : ans1) cout << x << " ";
    cout << "\n";
    for (int x : ans2) cout << x << " ";
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