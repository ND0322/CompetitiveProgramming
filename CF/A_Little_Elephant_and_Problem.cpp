#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main(){
    int n; cin >> n;

    int cnt = 0;

    ost s;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        cnt += s.order_of_key(x);

        s.insert(x);
    }

    if(cnt > 1) cout << "NO\n";
    else cout << "YES\n";
}