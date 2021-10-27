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

// Optimise from O(2^n) to O(2^(n/2) * log(2^(n/2)))

void solve(int tc = 0) {
    int n, m; cin >> n >> m;
    vector<int> a1(n / 2), a2(n - n / 2);
    for (int &x : a1) cin >> x;
    for (int &x : a2) cin >> x;
    vector<ll> s1, s2;
    for (int mask = 0; mask < (1 << sz(a1)); mask++) {
        ll sum = 0;
        for (int i = 0; i < sz(a1); i++) 
            if (mask & (1 << i)) 
                sum += a1[i];
        s1.push_back(sum);
    }
    for (int mask = 0; mask < (1 << sz(a2)); mask++) {
        ll sum = 0;
        for (int i = 0; i < sz(a2); i++) 
            if (mask & (1 << i)) 
                sum += a2[i];
        s2.push_back(sum);
    }
    sort(all(s1));
    ll ans = 0;
    for (ll x : s2) {
        ans += upper_bound(all(s1), m - x) - lower_bound(all(s1), m - x);
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