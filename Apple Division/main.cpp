#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ll ans = INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) sum1 += a[i];
            else sum2 += a[i];
        }
        ans = min(ans, abs(sum1 - sum2));
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