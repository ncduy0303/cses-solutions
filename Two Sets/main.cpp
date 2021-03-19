#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    ll n; cin >> n;
    ll tot = n * (n + 1) / 2;
    if (tot % 2) {
        cout << "NO\n";
        return;
    }
    tot /= 2;
    vector<int> a1, a2;
    for (ll i = n, sum = 0; i > 0; i--) {
        if (sum + i <= tot) {
            sum += i;
            a1.push_back(i);
        } else {
            a2.push_back(i);
        }
    }
    sort(a1.begin(), a1.end()); 
    sort(a2.begin(), a2.end());
    cout << "YES\n";
    cout << a1.size() << "\n";
    for (int x : a1) cout << x << " ";
    cout << "\n"; 
    cout << a2.size() << "\n";
    for (int x : a2) cout << x << " ";
    cout << "\n"; 
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