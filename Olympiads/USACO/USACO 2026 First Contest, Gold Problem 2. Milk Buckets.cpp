#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 2e5+5;

#define int long long

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ost;

/*
maxmial value when sorted 
minimum number of swaps such that each element is adjacent to the element left and right
in the sorted sequence 
first decreasing then increasing 
concave?

maybe dp able

consider from largest to smallest
we can either put it to the front or the back

min between number of things less in prefix and suffix

*/

int pref[MAXN], suf[MAXN];


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int cnt = 0;

        ost s;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            pref[i] = s.order_of_key(a[i]);
            s.insert(a[i]);
        }


        s.clear();

        for(int i = n; i >= 1; i--){
            suf[i] = s.order_of_key(a[i]);
            s.insert(a[i]);   
        }

        int ans = 0;

        for(int i = 1; i<= n; i++) ans += min(pref[i], suf[i]);
        

        cout << ans << "\n";

       



        
    }
}