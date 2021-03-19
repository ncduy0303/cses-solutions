#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAX_S = 1e6;
const int MAX_C = 26;
 
int n, m, tr[MAX_S][MAX_C], cnt[MAX_S], num;
string s;
 
void insert(string t) {
    int u = 0;
    for (char c : t) {
        if (!tr[u][c - 'a']) tr[u][c - 'a'] = ++num;
        u = tr[u][c - 'a'];
    }
    cnt[u]++;
}

void solve() {
    cin >> s >> m; n = s.size();
    for (int i = 0; i < m; i++) {
        string t; cin >> t;
        insert(t);
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int u = 0, len = 1;
        for (char c : s.substr(i)) {
            if (!tr[u][c - 'a']) break;
            u = tr[u][c - 'a'];
            if (cnt[u]) dp[i + len] = (dp[i + len] + dp[i]) % MOD;
            len++;
        }
    }
    cout << dp[n] << "\n";
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