#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    map<int,int> mp;
    ll ans = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if ((int)mp.size() == k && !mp.count(a[j])) {
            while ((int)mp.size() == k) {
                mp[a[i]]--;
                if (mp[a[i]] == 0) mp.erase(a[i]);
                i++;
            }
        }
        mp[a[j]]++;
        ans += j - i + 1;
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