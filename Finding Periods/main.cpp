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

ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int n = s.size(); 
    Hash Hs(s);
    for (int len = 1; len <= n; len++) {
        int q = n / len, r = n % len;
        auto Ha = Hs(0, n - r - 1);
        auto Hb = Hs(0, len - 1);
        for (int i = 0; i < NUM_MOD; i++) {
            Hb[i] = Hb[i] * (qexp(BASE, len * q, MODS[i]) - 1 + MODS[i]) % MODS[i] * (qexp(qexp(BASE, len, MODS[i]) - 1 + MODS[i], MODS[i] - 2, MODS[i])) % MODS[i];
        }
        if (Ha == Hb && Hs(0, r - 1) == Hs(n - r, n - 1)) cout << len << " ";
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