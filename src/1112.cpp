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

void add(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
ll mul(ll a, ll b) { return (ll) a * b % MOD; }
 
int n, m, pf[MAX_N], nxt[MAX_N][MAX_C];
string s;
 
void preprocess() {
    pf[0] = 0;
    for (int i = 1; i < m; i++) {
        int j = pf[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = pf[j - 1];
        pf[i] = j + (s[i] == s[j]);
    }
 
    for (int i = 0; i <= m; i++) {
        for (int c = 0; c < MAX_C; c++) {
            char cc = (char) ('A' + c);
            int j = (i == m ? pf[m - 1] : i);
            while (j > 0 && (s[j] != cc))
                j = pf[j - 1];
            nxt[i][c] = j + (s[j] == cc);
        }
    }
}
 
void solve(int tc = 0) {
    cin >> n >> s; m = sz(s);
    preprocess();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            for (int c = 0; c < MAX_C; c++)
                add(dp[i + 1][nxt[j][c]], dp[i][j]);
    int ans = 0, pw = 1;
    for (int i = n; i >= 0; i--) {
        add(ans, mul(dp[i][m], pw));
        pw = mul(pw, 26);
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