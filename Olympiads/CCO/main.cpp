#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e6+3;

int n, a[MAXN], dp[MAXN], st[MAXN<<2][2], near[MAXN], nearl[MAXN], last[MAXN], ub[2], cnt[MAXN][2];

//lazy seg tree keeping track of dps we can access as we slide right to left
//r is easy to transition just consider the new i when sliding over
//if a[l] is included in the previous range we will get old transitions and maybe new ones
//otherwise we can only consider the stuff from near[l] onward 
//all between near[l] and near[near[l]] can be claimed 
//bsearch for the right we can have between near[l] and near[near[l]]
//segtree for min near left + cnt min + one example representative 


void update(int node, int l, int r, int i, int x, bool t){
    if(l == r){
        st[node][t] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x, t);
    else update(node<<1|1, mid+1, r,i, x, t);
    st[node][t] = (st[node<<1][t] + st[node<<1|1][t]) % MOD;
}

int query(int node, int l, int r, int x, int y, bool t){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node][t];

    int mid = (l+r)>>1;
    return (query(node<<1, l, mid, x, y, t) + query(node<<1|1, mid+1,r,x,y,t)) % MOD;
}



   

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        last[a[i]] = n+1;
    }

    for(int i = n; i >= 1; i--){
        near[i] = last[a[i]];
        last[a[i]] = i;
    }

    for(int i = 1; i <= n; i++) last[a[i]] = 0;
    for(int i = 1; i <= n; i++){
        nearl[i] = last[a[i]];
        last[a[i]] = i;
    }

    for(int i = 1; i <= n; i++) cout << nearl[i] << " ";
    cout << "\n";

    

    dp[n+1] = 1;
    ub[0] = n;
    ub[1] = n;
    //update(1, 1, n+1, n+1, 1, (!n&1));
    //parity of lights

    //2 + 
    for(int i = n; i >= 1; i--){  
        ub[i&1] = min(ub[i&1], near[i]-1);

        
        cout << ub[i&1] << "\n";
        for(int j = i-2; j > nearl[i]; j -= 2) cnt[j][!(i&1)]++;
        for(int j = i+2; j < near[i]; j += 2) cnt[j][(!(i&1))]--;

        for(int j = 1; j <= n; j++) cout << cnt[j][0] << " ";
        cout << "\n";
        for(int j = 1; j <= n; j++) cout << cnt[j][1] << " ";
        cout << "\n";

        int cnt1 = 0;
        int cnt2 = 0;

        cout << i << " " << ub[i&1] << "\n";

        for(int j = i; j <= ub[i&1]; j++){
            if(!cnt[j][i&1]){
                dp[i] += dp[j+1];
                cnt1+= dp[j+1];
            }
        }

        for(int j = i+2; j <= ub[!(i&1)]; j++){
            if(!cnt[j][!(i&1)]){
                dp[i] += dp[j+1];
                cnt2 += dp[j+1];                
            }
        }

        cout << i << " " << dp[i] << " " << ub[i&1] << " " << ub[!(i&1)] << " " << cnt1 << " " << cnt2 << "\n"; 

        
    }

    cout << dp[1] << "\n";
}