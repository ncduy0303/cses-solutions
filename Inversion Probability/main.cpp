#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    double ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int r = min(a[j], a[i]);
            int t = r * (r - 1) / 2;
            if (a[j] > a[i]) t += a[i] * (a[j] - a[i]);
            ans += (double) t / (a[i] * a[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
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