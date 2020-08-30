#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e6 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

ll fact[MAX_N], invf[MAX_N];

int qexp(int A, int B, int M) {
    if (B == 0) return 1;
    ll half = qexp(A, B / 2, M);
    (half *= half) %= M;
    if (B % 2) (half *= A) %= M;
    return half;
}

void precompute() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		// invf[i] = qexp(fact[i], MOD - 2, MOD);
	}
}

void solve() {
    string s; cin >> s;
    vi cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    ll ans = fact[s.size()];
    for (int x : cnt) (ans *= qexp(fact[x], MOD - 2, MOD)) %= MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    precompute();
    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
