#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<ar<ll,2>> a(n);
    for (auto &[p, k] : a) cin >> p >> k;
    ll cnt = 1, sum = 1, mul = 1, cnt2 = 1;
    for (auto [p, k] : a) {
        cnt = cnt * (k + 1) % MOD;
        sum = sum * (qexp(p, k + 1, MOD) - 1) % MOD * qexp(p - 1, MOD - 2, MOD) % MOD;
        mul = qexp(mul, k + 1, MOD) * qexp(qexp(p, k * (k + 1) / 2, MOD), cnt2, MOD) % MOD;
        cnt2 = cnt2 * (k + 1) % (MOD - 1);
    }
    cout << cnt << " " << sum << " " << mul << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}