#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll ap(ll l, ll r) { // = l + (l + 1) + ... + r
	l %= MOD; r %= MOD;
	ll res = r * (r + 1) / 2 % MOD - l * (l - 1) / 2 % MOD;
	if (res < 0) res += MOD;
	return res;
}

void solve() {
    ll n; cin >> n;
	ll ans = 0;
	for (ll l = 1, r, k; l <= n; l = r + 1) {
		k = n / l; 
		r = n / k;
		ans = (ans + k * ap(l, r) % MOD) % MOD;
	}
	cout << ans << "\n";
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