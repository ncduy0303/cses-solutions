#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; ll s; cin >> n >> s;
	int m = n / 2; n -= m;
	vector<int> a1(n), a2(m);
	for (int &x : a1) cin >> x;
	for (int &x : a2) cin >> x;
	vector<ll> s1, s2;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (mask >> i & 1) sum += a1[i];
		}
		s1.push_back(sum);
	}
	for (int mask = 0; mask < (1 << m); mask++) {
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			if (mask >> i & 1) sum += a2[i];
		}
		s2.push_back(sum);
	}
	sort(s2.begin(), s2.end());
	ll ans = 0;
	for (ll x : s1) {
		ans += upper_bound(s2.begin(), s2.end(), s - x) - lower_bound(s2.begin(), s2.end(), s - x);
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