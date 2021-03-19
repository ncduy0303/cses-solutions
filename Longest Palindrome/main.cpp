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
    string t(s.rbegin(), s.rend());
    int n = s.size();
    Hash Hs(s), Ht(t);
 
    auto is_palindrome = [&](int l, int r) {
        return same(Hs(l, r), Ht(n - r - 1, n - l - 1));
    };
 
    auto ok = [&](int mid) {
        for (int l = 0, r = mid - 1; r < n; l++, r++) {
            if (is_palindrome(l, r)) return true;
        }
        return false;
    };
 
    int lo1 = 0, hi1 = n;
    while (lo1 + 1 < hi1) {
        int mid = (lo1 + hi1) / 2;
        if (ok(2 * mid)) lo1 = mid;
        else hi1 = mid;
    }
    int lo2 = 0, hi2 = n;
    while (lo2 + 1 < hi2) {
        int mid = (lo2 + hi2) / 2;
        if (ok(2 * mid + 1)) lo2 = mid;
        else hi2 = mid;
    }
    int len = max(2 * lo1, 2 * lo2 + 1);
    for (int l = 0, r = len - 1; r < n; l++, r++) {
        if (is_palindrome(l, r)) {
            cout << s.substr(l, r - l + 1) << "\n";
            return;
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