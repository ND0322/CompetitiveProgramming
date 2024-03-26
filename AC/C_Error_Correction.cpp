#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int>ans;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(s == t) {
            ans.push_back(i);
        } else {
            int diff = 0;
            bool f = true;
            for(int i = 0; i < max(s.size(), t.size()); i++) {
                if(s[i + (s.size() > t.size()) * diff] != t[i + (s.size() < t.size()) * diff]) {
                    diff++;
                    if(diff > 1) {
                        f = false;
                        break;
                    }
                    if(s.size() != t.size()) i--;
                }
            }
            if(f) ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << " ";
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
