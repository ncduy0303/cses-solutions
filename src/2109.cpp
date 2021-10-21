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
 
template<char MIN_CHAR = 'a', int ALPHA = 26> struct SuffixAutomaton {
    int last;
    vector<int> len, link;
    vector<ll> cnt;
    vector<ar<int,2>> order;
    vector<array<int, ALPHA>> nxt;
 
    SuffixAutomaton() : last(0), len(1), link(1, -1), cnt(1), nxt(1) {}
 
    SuffixAutomaton(const string &s) : SuffixAutomaton() {
        for (char c : s)
            extend(c);
    }
 
    int getIndex(char c) {
        return c - MIN_CHAR;
    }
 
    void extend(char c) {
        int cur = (int) len.size(), i = getIndex(c), p = last;
        len.push_back(len[last] + 1);
        link.emplace_back();
        cnt.push_back(1);
        order.push_back({len[cur], cur});
        nxt.emplace_back();
        while (p != -1 && !nxt[p][i]) {
            nxt[p][i] = cur;
            p = link[p];
        }
        if (p != -1) {
            int q = nxt[p][i];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = (int) len.size();
                len.push_back(len[p] + 1);
                link.push_back(link[q]);
                cnt.push_back(0);
                order.push_back({len[clone], clone});
                nxt.push_back(nxt[q]);
                while (p != -1 && nxt[p][i] == q) {
                    nxt[p][i] = clone;
                    p = link[p];
                }
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
    }
};
 
void solve(int tc = 0) {
    string s; ll k; cin >> s >> k;
    SuffixAutomaton sa(s);
 
    sort(sa.order.rbegin(), sa.order.rend());
    for (auto [_, u]: sa.order) {
        sa.cnt[sa.link[u]] += sa.cnt[u];
    }
 
    vector<ll> dp(sa.last + 1);
    function<void(int)> dfs = [&](int u) {
        dp[u] = sa.cnt[u];
        for (int i = 0; i < 26; i++) {
            if (!sa.nxt[u][i]) continue;
            int v = sa.nxt[u][i];
            if (!dp[v]) dfs(v);
            dp[u] += dp[v]; 
        }
    };
    dfs(0);
 
    int u = 0;
    while (k > 0) {
        for (int i = 0; i < 26; i++) {
            if (!sa.nxt[u][i]) continue;
            int v = sa.nxt[u][i];
            if (k > dp[v]) {
                k -= dp[v];
            } else {
                cout << (char) ('a' + i);
                k -= sa.cnt[v];
                u = v;
                break;
            }
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