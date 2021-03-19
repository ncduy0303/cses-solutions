#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<ar<int,3>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r, i};
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    for (auto [l, r, i] : a) {
        if (pq.empty() || l <= pq.top()[0]) {
            ans[i] = pq.size() + 1;
        } else {
            ans[i] = pq.top()[1];
            pq.pop();
        }
        pq.push({r, ans[i]});
    }
    cout << pq.size() << "\n";
    for (int x : ans) cout << x << " ";
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