#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vector<int> ans, vis;
 
string to_str(int x) {
    string s;
    for (int i = 0; i < n; i++) s += (x >> i & 1) ? "1" : "0";
    reverse(s.begin(), s.end());
    return s;
}
 
void backtrack(int pos, int x) {
    vis[x] = 1;
    ans.push_back(x);
    if (pos == (1 << n) - 1) {
        for (int nx : ans) cout << to_str(nx) << "\n";
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        int nx = x ^ (1 << i);
        if (vis[nx]) continue;
        backtrack(pos + 1, nx);
        vis[nx] = 0;
        ans.pop_back();
    }
}

void solve() {
    cin >> n;
    vis.assign(1 << n, 0);
    backtrack(0, 0);
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