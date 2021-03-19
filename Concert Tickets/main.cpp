#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n, m; cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        int x; cin >> x;
        ms.insert(x);
    }
    while (m--) {
        int x; cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.begin()) cout << -1 << "\n";
        else {
            it = prev(it);
            cout << *it << "\n";
            ms.erase(it);
        }
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