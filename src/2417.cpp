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

const int MAX = 1e6 + 5;
 
bitset<MAX> isPrime;
vector<int> primes;
int spf[MAX];
int mobius[MAX];
 
void sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    mobius[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
            mobius[i] = -1;
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= (MAX - 1) / i; j++) {
            int p = primes[j];
            isPrime[i * p] = 0;
            spf[i * p] = p;
            mobius[i * p] = (spf[i] == p) ? 0 : -mobius[i];
            if (i % primes[j] == 0) break;
        }
    }
}
 
void solve(int tc = 0) {
    sieve();
    int n; cin >> n;
    vector<int> cnt(MAX);
    while (n--) {
        int x; cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    for (int i = 1; i < MAX; i++) {
        ll num = 0;
        for (int j = i; j < MAX; j += i) num += cnt[j];
        ans += num * (num - 1) / 2 * mobius[i];
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