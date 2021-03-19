#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    ll n; cin >> n;
    ll pos = 0, len = 1, p10 = 1;
    while (pos < n) {
        pos += len * p10 * 9;
        len++;
        p10 *= 10;
    }
    len--; p10 /= 10; pos -= len * p10 * 9;
    ll push = (n - pos - 1) / len;
    string ans = to_string(p10 + push);
    ll id = n - (pos + push * len) - 1;
    cout << ans[id] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}