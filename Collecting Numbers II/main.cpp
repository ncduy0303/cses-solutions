#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 0;
    vector<bool> used(n + 1);
    for (int i = 1; i <= n; i++) {
        ans += !used[a[i] - 1];
        used[a[i]] = true;
    }
    while (q--) {
        int i, j; cin >> i >> j;
        if (i > j) swap(i, j);
        int x = a[i], y = a[j];
        if (x + 1 <= n && i < pos[x + 1] && pos[x + 1] < j) ans++;
        if (x - 1 >= 1 && i < pos[x - 1] && pos[x - 1] < j) ans--;
        if (y + 1 <= n && i < pos[y + 1] && pos[y + 1] < j) ans--;
        if (y - 1 >= 1 && i < pos[y - 1] && pos[y - 1] < j) ans++;
        if (x + 1 == y) ans++;
        if (x - 1 == y) ans--;
        swap(a[i], a[j]);
        swap(pos[a[i]], pos[a[j]]);
        cout << ans << "\n";
    }
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