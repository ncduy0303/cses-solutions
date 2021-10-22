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

// [l, r] -> (a[l] + 1, a[l + 1] + 2, ..., a[r] + (r - l + 1))
// -> sum[l, r] += (1 + 2 + ... + (r - l + 1)) = (r - l) * (r - l + 1) / 2 = 0 * len + ap
// for l <= i <= r
// -> sum[i, l] = 0 * len + ap
// -> sum[i, r] += (i - l + 1) + (i - l + 2) + ... + (r - l + 1) 
// = (i - l) * len + (1 + 2 + ... + (r - i + 1))
// = (i - l) * len + ap
 
struct Node {
    ll sum, lzc, lzd;
    Node(): sum(0), lzc(0), lzd(0) {}
    Node(ll x): sum(x), lzc(0), lzd(0) {}
    Node(const Node &l, const Node &r) {
        sum = l.sum + r.sum;
        lzc = 0;
        lzd = 0;
    }
};
 
struct SegmentTree { 
    int ln(int node) { return 2 * node; }
    int rn(int node) { return 2 * node + 1; }
 
    int n; vector<Node> st;
 
    void init(int _n) { n = _n; st.resize(4 * _n); }
    void init(const vector<int> &a) { init(sz(a)); build(a, 1, 0, n - 1); }
 
    void apply(int node, int start, int end, ll c, ll d) {
        ll len = end - start + 1;
        ll aps = len * (len + 1) / 2;
        st[node].sum += len * c + aps * d;
        st[node].lzc += c;
        st[node].lzd += d;
    }
 
    void push_down(int node, int start, int end) {
        if (start == end) return;
        int mid = (start + end) / 2;
        apply(ln(node), start, mid, st[node].lzc, st[node].lzd);
        apply(rn(node), mid + 1, end, st[node].lzc + st[node].lzd * (mid + 1 - start), st[node].lzd);
        st[node].lzc = 0;
        st[node].lzd = 0;
    }
 
    void build(const vector<int> &a, int node, int start, int end) {
        if (start == end) {
            st[node] = Node(a[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(a, ln(node), start, mid);
        build(a, rn(node), mid + 1, end);
        st[node] = Node(st[ln(node)], st[rn(node)]);
    }
 
    void update(int node, int start, int end, int l, int r) {
        push_down(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, start - l, 1);
            return;
        }
        int mid = (start + end) / 2;
        update(ln(node), start, mid, l, r);
        update(rn(node), mid + 1, end, l, r);
        st[node] = Node(st[ln(node)], st[rn(node)]);
    }
 
    Node query(int node, int start, int end, int l, int r) {
        push_down(node, start, end);
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        return Node(query(ln(node), start, mid, l, r), query(rn(node), mid + 1, end, l, r));
    }
    
    void update(int l, int r) { update(1, 0, n - 1, l, r); }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
 
void solve(int tc = 0) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SegmentTree st; st.init(a);
    while (q--) {
        int t, l, r; cin >> t >> l >> r; l--; r--;
        if (t == 1) {
            st.update(l, r);
        } else {
            cout << st.query(l, r).sum << "\n";
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