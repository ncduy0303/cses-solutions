#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n; i >= 1; i--) {
        int tmp = i;
        while (tmp) {
            int d = tmp % 10;
            tmp /= 10;
            dp[i - d] = min(dp[i - d], dp[i] + 1);
        }
    }
    cout << dp[0] << "\n";
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