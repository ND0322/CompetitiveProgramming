#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e6+3;

int n, a[MAXN], dp[MAXN], st[MAXN<<2][2], near[MAXN], nearl[MAXN], last[MAXN], ub[2], cnt[MAXN][2];

/*
denote si as the set of reachable indices assuming i is light and ti as the set of reachable indices assuming i is heavy
si = ti+1[:r]
ti = si+1[near[i]:]

however, elements between near[i] and near[near[i]]-1 are updated
think of ti updates as removing an old range and adding a new one
when adding our new range will intersect with some old ranges and in that case we merge it
all [i:whatever r] are now invalid 
we also only care about the intersected range with the max r as all other points will naturally be covered 
the right becomes the old left-1
when removing the old range
any left intersection is kept and right intersection is removed 
a gap is created from the right of the lsect to the left of the rsect 


*/

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

    

    dp[n+1] = 1;
    ub[0] = n;
    ub[1] = n;
    //update(1, 1, n+1, n+1, 1, (!n&1));
    //parity of lights

    //2 + 
    for(int i = n; i >= 1; i--){  
        ub[i&1] = min(ub[i&1], near[i]-1);

        
        cout << ub[i&1] << "\n";

        
        for(int j = i; j >= nearl[i]; j--) cnt[j][!(i&1)]++;
        if(near[i] != n+1) for(int j = i; j <= near[i]; j++) cnt[j][(!(i&1))]--;


        for(int j = 1; j <= n; j++) cout << cnt[j][0] << " ";
        cout << "\n";
        for(int j = 1; j <= n; j++) cout << cnt[j][1] << " ";
        cout << "\n";


        int cnt1 = 0;
        int cnt2 = 0;

        dp[i] = dp[i+1];

        for(int j = i+2; j <= ub[i&1]; j++){
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