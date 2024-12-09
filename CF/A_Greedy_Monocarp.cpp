#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define err(x) cout << #x << " = " << x << endl
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) begin(x), end(x)
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int INF = 0x3f3f3f3f;
const int MX = 200005;
int n, k, a[MX];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i];
        if (cnt == k) {
            cout << "0\n";
            return;
        }
        if (cnt > k) {
            cnt -= a[i];
            cout << k - cnt << '\n';
            return;
        }
    }
    cout << k - cnt << '\n';
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
/*

*/