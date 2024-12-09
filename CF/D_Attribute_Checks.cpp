#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//pretty easy dp
//state is current point and count of a
//range query all things between 
//as we move left we can update a set and bsearch for all a 
//this shit is too hard throw a merge sort tree on there 

const int MAXN = 5005;
const int MAXM = 2e6+5;


typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

int n,m, a[MAXM], dp[MAXN][MAXN], pos[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> m >> n;

    int cnt = 0;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        if(!a[i]) pos[++cnt] = i;
    }
    pos[n+1] = m+1;
    
    
    for(int i = n; i >= 1; i--){

        ost p,q;

        for(int j = pos[i]; j < pos[i+1]; j++){
			if(!a[j]) continue;
            if(a[j] < 0) q.insert(-a[j]);
            else p.insert(a[j]);
            
        }

        for(int j = 0; j < i; j++){
            
            int opt1 = q.order_of_key(i - j) + p.order_of_key(j+2) + dp[i+1][j+1];
            int opt2 = q.order_of_key(i - j + 1) + p.order_of_key(j+1) + dp[i+1][j];
            
      
            
            dp[i][j] = max(opt1, opt2);
        }
        
    }

    cout << dp[1][0] << "\n";
}
