#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, t, a[MAX_N];
 
bool ok(ll mid) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mid / a[i];
        if (cnt >= t) return true;
    }
    return false;
}

void solve() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll lo = 0, hi = INF;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << "\n";
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