#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <set>

#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN];

long long inv(int n, int a[]){
    ost tree;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i - tree.order_of_key(a[i]);
        tree.insert(a[i]);
    }

    return ans;
}

int32_t main() {
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		
        set<int> aa;
        set<int> bb;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            aa.insert(a[i]);
        }

        for(int i = 1; i <= n; i++){
            cin >> b[i];
            bb.insert(b[i]);
        }

        if(aa != bb){
            cout << "NO\n";
            continue;
        }
    

        long long inva = inv(n, a);
        long long invb = inv(n,b);

        if((inva & 1) == (invb&1)) cout << "YES\n";
        else cout << "NO\n";


	}
}