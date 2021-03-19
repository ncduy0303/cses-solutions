#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> ps(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ps[i] = ps[i - 1] + x;
    }
    ll ans = -INF;
    multiset<ll> ms;
    for (int i = 1; i <= n; i++) {
        if (i < a) continue;
        if (i > b) ms.erase(ms.find(ps[i - b - 1]));
        ms.insert(ps[i - a]);
        ans = max(ans, ps[i] - *ms.begin());
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