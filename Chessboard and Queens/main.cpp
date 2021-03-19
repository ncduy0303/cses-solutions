#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

const int n = 8;
 
vector<int> masks(n);
 
int backtrack(int r, int c, int ld, int rd) {
    if (r == n) return 1;
    int res = 0, mask = masks[r] | c | ld | rd;
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) continue;
        res += backtrack(r + 1, c | (1 << i), (ld | (1 << i)) << 1, (rd | (1 << i)) >> 1); 
    }
    return res;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '*') masks[i] |= (1 << j);
        }
    }
    cout << backtrack(0, 0, 0, 0) << "\n";
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