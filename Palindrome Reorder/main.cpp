#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    string s; cin >> s;
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'A']++;
    int odd = 0;
    for (int i = 0; i < 26; i++) odd += cnt[i] % 2;
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 0) {
            for (int j = 0; j < cnt[i] / 2; j++) cout << char('A' + i);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) {
            for (int j = 0; j < cnt[i]; j++) cout << char('A' + i);
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (cnt[i] % 2 == 0) {
            for (int j = 0; j < cnt[i] / 2; j++) cout << char('A' + i);
        }
    }
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