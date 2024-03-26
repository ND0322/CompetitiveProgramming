#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main(){
    int tt; cin >> tt;

    while(tt--){

        int n; cin >> n;
        vector<pair<int,int>> a(n);

        for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end());

        ost s;

        ll ans = 0;

        for(int i = 0; i < n; i++){
            ans += s.size() - s.order_of_key(a[i].second);
            s.insert(a[i].second);
        }

        cout << ans << "\n";
    }
}
//num greater for each