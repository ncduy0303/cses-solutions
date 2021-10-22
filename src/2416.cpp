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

// query(l, r) = sum of (max(a[l..i]) - a[i]) for i in [l..r]
int n, q, nxt[MAX_N][MAX_L];
ll a[MAX_N], ps[MAX_N], snxt[MAX_N][MAX_L];
 
ll query(int l, int r) {
    ll ans = ps[l - 1] - ps[r];
    for (int k = MAX_L - 1; k >= 0; k--) {
        if (nxt[l][k] != -1 && nxt[l][k] <= r) {
            ans += snxt[l][k];
            l = nxt[l][k];
        }
    }
    ans += a[l] * (r - l + 1);
    return ans;
}
 
void solve(int tc = 0) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    memset(nxt, -1, sizeof nxt);
    stack<int> st;
    for (int i = n; i > 0; i--) {
        while (st.size() && a[i] >= a[st.top()]) st.pop();
        nxt[i][0] = st.empty() ? n + 1 : st.top();
        snxt[i][0] = a[i] * (nxt[i][0] - i);
        st.push(i);
    }
    for (int k = 1; k < MAX_L; k++) {
        for (int i = 1; i <= n; i++) {
            if (nxt[i][k - 1] == -1) continue;
            nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
            snxt[i][k] = snxt[i][k - 1] + snxt[nxt[i][k - 1]][k - 1];
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << "\n";
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