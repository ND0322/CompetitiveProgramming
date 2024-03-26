#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;



int n, m, k, d, a[105][MAXN];

long long dp[MAXN][105], st[MAXN<<2];

//run segtree optimized dp for each row and then do the answer 

void update(int node, int l, int r, int i, long long x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return min(query(node<<1,l,mid,x,y), query(node<<1|1, mid+1,r,x,y));
}

void solve(){
    cin >> n >> m >> k >> d;

    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
        
    }


    for(int j = 1; j <= n; j++){
        dp[j][m] = 1;
        for(int i = 1; i <= m; i++) update(1,1,m,i,1e18);
        update(1,1,m,m, 1);
        for(int i = m-1; i >= 1; i--){
            dp[j][i] = query(1,1,m,i+1, min(i+d+1, m)) + a[j][i] + 1;
            update(1,1,m, i, dp[j][i]);
        }
    }

    long long ans = 1e18;

    for(int i = 1; i <= n-k+1; i++){
        long long sum = 0;
        for(int j = 0; j < k; j++) sum += dp[i+j][1];
        ans = min(ans, sum);
    }

    cout << ans << "\n";

}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();
}

