#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void backtrack(int n, int u, int v, int m) {
    if (n == 1) {
        cout << u << " " << v << "\n";
        return;
    }
    backtrack(n - 1, u, m, v);
    cout << u << " " << v << "\n";
    backtrack(n - 1, m, v, u);
}

void solve() {
    int n; cin >> n;
    cout << (1 << n) - 1 << "\n";
    backtrack(n, 1, 3, 2);
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