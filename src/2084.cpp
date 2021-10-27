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

// CHT optimisation DP
// dp[i] = min cost to end at i-th
// dp[i] = min{ dp[j] + f[j] * s[i] }, where j < i
 
// given 1 <= s[1] <= s[2] <= ... <= s[n] <= 1e6
// given x >= f[1] >= f[2] >= ... >= f[n] >= 1
 
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
 
void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<int> s(n), f(n);
    for (int &x : s) cin >> x;
    for (int &x : f) cin >> x;
    vector<ll> dp(n);
    LineContainer cht;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = (ll) m * s[i];
        } else {
            dp[i] = min((ll) m * s[i], cht.query(s[i]));
        }
        cht.add(f[i], dp[i]);
    }
    cout << dp[n - 1] << "\n";
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