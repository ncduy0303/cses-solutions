#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
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

ll sum(ll l, ll r) {
    l %= MOD; r %= MOD;
    ll sr = r * (r + 1) / 2 % MOD;
    ll sl = l * (l - 1) / 2 % MOD;
    ll res =  (sr - sl + MOD) % MOD;
    return res;
}

void solve() {
    ll n; cin >> n;
    ll ans = 0; 
    
    // naive approach: loop through all divisors and multiply by floor(n/i) (no.of time the divisor occurs) => O(n) => TLE
    // for (ll i = 1; i <= n; i++) 
    //     (ans += i * (n / i)) %= MOD;

    // lemma: there are at most 2 * sqrt(n) distinct values among floor(n/1), floor(n/2), ..., floor(n/n)
    // https://codeforces.com/blog/entry/53925
    // loop through all distinct values of floor(n/i) and multiply by AP sum of the divisors in [l..r]
    for (ll l = 1, r; l <= n; l = r + 1) { 
        r = n / (n / l);
        ll ap = sum(l, r);
        ll fl = (n / l) % MOD;
        (ans += ap * fl) %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
