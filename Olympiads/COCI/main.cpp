#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MX = 1e8;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0;

    for (int x : a) {
        int sq = sqrt(x);

        // Case 1: small j (direct)
        for (int j = 1; j <= min(k, sq); j++) {
            int val = (x / j) * (x + 2);
            ans += min(MX, val);
        }

        // Case 2: group by floor(x / j)
        for (int v = 1; v <= sq; v++) {
            int L = x / (v + 1) + 1;
            int R = x / v;

            L = max(L, sq+1);

            if (L > k) continue;
            R = min(R, k);
            if (L > R) continue;

            int val = v * (x + 2);
            val = min(val, MX);

            ans += (R - L + 1) * val;
        }
    }

    cout << ans << "\n";
}