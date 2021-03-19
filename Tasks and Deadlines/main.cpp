#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<ar<int,2>> a(n);
    for (auto &[t, d] : a) cin >> t >> d;
    sort(a.begin(), a.end());
    ll ans = 0, pre = 0;
    for (auto [t, d] : a) {
        pre += t;
        ans += d - pre;
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