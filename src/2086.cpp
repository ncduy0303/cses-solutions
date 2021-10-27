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

struct Line {
    ll m, c; 
    Line(ll m, ll c): m(m), c(c) {}
    ll operator()(ll x) { return m * x + c; }
};
 
struct LineContainer {
    deque<Line> dq;
    bool check(Line p1, Line p2, Line p3) { // p1.m > p2.m > p3.m
        return (p1.m - p2.m) * (p2.c - p3.c) >= (p2.m - p3.m) * (p1.c - p2.c);
    }
    void add(ll m, ll c) { // decreasing slope
        Line y(m, c);
        while (sz(dq) >= 2 && check(dq[sz(dq) - 2], dq[sz(dq) - 1], y)) dq.pop_back();
        dq.push_back(y);
    }
    ll query(ll x) { // min query, increasing x
        while (sz(dq) >= 2 && dq[0](x) >= dq[1](x)) dq.pop_front();
        return dq[0](x);
    }
};

// CHT Optimisation DP 
// ndp[i] = min { dp[j] + cost(j + 1, i) }, where j < i
// ndp[i] = min { dp[j] + (ps[i] - ps[j]) * (ps[i] - ps[j]) }
// ndp[i] = ps[i] * ps[i] + min { dp[j] + ps[j] * ps[j] - 2 * ps[j] * ps[i] }
 
// notice -2 * ps[j] is always decreasing
// notice ps[i] is always increasing
 
void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<ll> ps = {0};
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ps.push_back(ps.back() + x);
    }
    vector<ll> dp(n + 1, LLONG_MAX);
    for (int i = 1; i <= n; i++) dp[i] = ps[i] * ps[i]; 
    for (int j = 2; j <= m; j++) {
        LineContainer cht;
        vector<ll> ndp(n + 1, LLONG_MAX);
        for (int i = j; i <= n; i++) {
            cht.add(-2 * ps[i - 1], dp[i - 1] + ps[i - 1] * ps[i - 1]);
            ndp[i] = ps[i] * ps[i] + cht.query(ps[i]);
        }
        dp = ndp;
    }
    cout << dp[n] << "\n";
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