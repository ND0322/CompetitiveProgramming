#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ost;


using namespace std;


//bsearch on answer
/*
number of inversions ish on the suffix for each node 
*/



const int MAXN = 3e5+5;

int n, a[MAXN];

long long k;

bool can(int x){
    ost s;
    long long cap = k;
    multiset<int> zeros; 
    for(int i = n; i >= 1; i--){

        if(s.empty()){
            s.insert(a[i]);
            if(!a[i]) zeros.insert(0);
            continue;
        }
        

        
        if((int)(s.order_of_key(a[i])) - x > (int)zeros.size()) return 0;  
        
        while((int)s.order_of_key(a[i]) > x){
            auto it = zeros.lower_bound(-a[i]+1);
            
            //-4 0
        
            if(it == zeros.end()) return 0;
            

            
            int v = -*it;
    
    
            if(a[i] - v > cap) return 0;
            
            zeros.erase(zeros.find(-v));
            s.erase(s.find_by_order(s.order_of_key(v)));

            zeros.insert(-a[i]);
            s.insert(a[i]);

            cap -= (a[i] - v);
        }

        s.insert(a[i]);
        if(!a[i]) zeros.insert(a[i]);
        
    }
    return 1;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int lo = 0;
    int hi = n;
    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";
}