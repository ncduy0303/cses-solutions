#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int kmp[MAX_N];

void kmp_preprocess(string P) {
    int i = 0, j = -1; kmp[0] = -1;
    while (i < P.size()) { 
        while (j >= 0 && P[i] != P[j]) j = kmp[j];
        i++; j++; 
        kmp[i] = j;
    }
}

void solve() {
    int n; string s; cin >> n >> s;
    int m = s.size();
    kmp_preprocess(s);
    
    int dp[n + 1][m + 1] = {};
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                int k = j;
                while (k && s[k] != c) k = kmp[k];
                if (s[k] == c) k++;
                (dp[i + 1][k] += dp[i][j]) %= MOD;
            }
        }
    }
 
    ll ans = 0, mul = 1;
    for (int i = n; i >= m; i--) {
        (ans += dp[i][m] * mul) %= MOD;
        (mul *= 26) %= MOD;
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