#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    if (n == 1) cout << 1 << "\n";
    else if (n == 2 || n == 3) cout << "NO SOLUTION\n";
    else {
        for (int i = n; i > 0; i--) if (i % 2 == 1) cout << i << " ";
        for (int i = n; i > 0; i--) if (i % 2 == 0) cout << i << " ";
        cout << "\n";
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