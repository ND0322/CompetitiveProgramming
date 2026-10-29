#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int k = 31 - __builtin_clz(n);
        int S = 1 << (k + 1);

        vector<int> ans;

        for (int i = 1; i < 2 * S; i++) {
            int prev = (i - 1) % S;
            int curr = i % S;

            int a = (prev ^ (prev >> 1))
                  ^ (curr ^ (curr >> 1));

            ans.push_back(a);
        }

        cout << ans.size() << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}