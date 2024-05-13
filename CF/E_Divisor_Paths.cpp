#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()

using ll = long long;
using ld = long double;

constexpr ll mod = 998244353;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll d;
    cin >> d;
    vector<ll> divs;
    for (ll i = 1; i*i <= d; i++) {//is this fast enough?
        if (d % i == 0) {
            divs.push_back(i);
            if (i*i != d) divs.push_back(d/i);
        }
    }
    vector<ll> ps;
    for (ll i = 2; i*i <= d; i++) {
        if (d % i == 0) {
            ps.push_back(i);
            while (d % i == 0) d /= i;
        }
    }
    if (d > 1) ps.push_back(d);
    sort(all(divs));
    vector<ll> res(sz(divs));
    res[0] = 1;
    for (ll i = 0; i < sz(divs); i++) {
        for (ll p : ps) {
            if (divs[i] % p == 0) {
                ll j = distance(divs.begin(), lower_bound(all(divs), divs[i]/p));
                res[i] += res[j];
                res[i] %= mod;
            }
        }
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        ll g = gcd(u, v);
        u = distance(divs.begin(), lower_bound(all(divs), u/g));
        v = distance(divs.begin(), lower_bound(all(divs), v/g));
        cout << ((res[u] * res[v]) % mod) << "\n";
    }
}