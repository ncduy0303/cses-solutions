#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution(l, r)(rng);}
const int BASE = rand(300, 1e9);
const int NUM_MOD = 4;
const ll MODS[] = {(int)1e9 + 2277};
struct Hash {
    vector<ll> H[NUM_MOD], P[NUM_MOD];
    Hash(string s) {
        for (int i = 0; i < NUM_MOD; i++) {
            H[i].push_back(0);
            P[i].push_back(1);
        }
        for (char c : s) {
            for (int i = 0; i < NUM_MOD; i++) {
                P[i].push_back(P[i].back() * BASE % MODS[i]);
                H[i].push_back((H[i].back() * BASE + c) % MODS[i]);
            }
        }
    } 
    ar<ll, NUM_MOD> operator()(int l, int r) {
        ar<ll,NUM_MOD> res;
        for (int i = 0; i < NUM_MOD; i++) {
            res[i] = (H[i][r + 1] - H[i][l] * P[i][r + 1 - l]) % MODS[i];
            if (res[i] < 0) res[i] += MODS[i];
        }
        return res;
    }
};

bool same(ar<ll,NUM_MOD> a, ar<ll, NUM_MOD> b) {
    for (int i = 0; i < NUM_MOD; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    s += s;
    Hash Hs(s);
 
    auto cmp = [&](int a, int b) {
        if (s[a] != s[b]) return s[a] < s[b];
        if (same(Hs(a, a + n - 1), Hs(b, b + n - 1))) return false;
        int lo = 1, hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (same(Hs(a, a + mid - 1), Hs(b, b + mid - 1))) lo = mid;
            else hi = mid;
        }
        return s[a + hi - 1] < s[b + hi - 1];
    };
 
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if (cmp(i, mn)) mn = i;
    }
    cout << s.substr(mn, n) << "\n";
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