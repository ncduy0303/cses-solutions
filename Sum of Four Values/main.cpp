#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int,2>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }
    sort(a.begin(), a.end());
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            for (int i = v + 1, j = n - 1; i < j;) {
                if (a[u][0] + a[v][0] + a[i][0] + a[j][0] == m) {
                    cout << a[u][1] << " " << a[v][1] << " " << a[i][1] << " " << a[j][1] << "\n";
                    return;
                } else if (a[u][0] + a[v][0] + a[i][0] + a[j][0] < m) {
                    i++;
                } else {
                    j--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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