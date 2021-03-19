#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    map<int,int> mp;
    while (n--) {
        int l, r; cin >> l >> r;
        mp[l]++; mp[r + 1]--;
    }
    int ans = 0, cur = 0;
    for (auto [pos, cnt] : mp) {
        cur += cnt;
        ans = max(ans, cur);
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