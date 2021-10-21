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
const ll INF = 1e9;
const ld EPS = 1e-9;

typedef unsigned long long ull;
 
int gen() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ ull(new ull));
    uniform_int_distribution<int> dist(258, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}
 
static const ull MOD = (1ULL << 61) - 1;
static int BASE = gen();
 
static inline ull add(ull a, ull b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
 
static inline ull sub(ull a, ull b) {
    a -= b;
    if (a >= MOD)
        a += MOD;
    return a;
}
 
static inline ull mul(ull a, ull b) {
    ull l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    ull ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
}
 
struct SegmentTree {
    int n; vector<ull> st;
    
    void init(int _n) { n = _n; st.resize(2 * _n); }
 
    ull query(int l, int r) {
        ull res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = add(res, st[l++]);
            if (r & 1) res = add(res, st[--r]);
        }
        return res;
    }
 
    void update(int i, ull x) {
        for (st[i += n] = x; i > 1; i >>= 1) st[i >> 1] = add(st[i], st[i ^ 1]);
    }
};
 
vector<ull> power;
 
void solve(int tc = 0) {
    int n, q; string s; cin >> n >> q >> s;
    while ((int) power.size() <= (int) s.length())
        power.push_back(power.empty() ? 1 : mul(power.back(), BASE));
    SegmentTree st1, st2;
    st1.init(n); st2.init(n);
    for (int i = 0; i < n; i++) {
        st1.update(i, mul(power[i], s[i]));
        st2.update(i, mul(power[n - 1 - i], s[i]));
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c; i--;
            s[i] = c;
            st1.update(i, mul(power[i], s[i]));
            st2.update(i, mul(power[n - 1 - i], s[i]));
        } else {
            int l, r; cin >> l >> r; l--; r--;
            ull hs1 = mul(power[n - 1 - r], st1.query(l, r));
            ull hs2 = mul(power[l], st2.query(l, r));
            cout << (hs1 == hs2 ? "YES" : "NO") << "\n";
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