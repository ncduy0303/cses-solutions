#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    ll x, y; cin >> x >> y;
    if (x >= y) {
        cout << (x % 2 ? (x - 1) * (x - 1) + y : x * x - y + 1) << "\n"; 
    } else {
        cout << (y % 2 ? y * y - x + 1 : (y - 1) * (y - 1) + x) << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}