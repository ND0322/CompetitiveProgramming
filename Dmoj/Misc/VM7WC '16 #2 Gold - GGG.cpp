#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n,m,a[MAXN], b[MAXN], c[MAXN], dp[MAXN], ind[MAXN], st[MAXN<<2];

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return max(query(node<<1,l,mid,x,y),query(node<<1|1,mid+1,r,x,y));
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;



    for(int i = 1; i <= m; i++) cin >> b[i];

   
    for(int i = 1; i <= n; i++) ind[a[i]] = i;

    for(int i = 1; i <= m; i++){
        if(!ind[b[i]]) continue;

        dp[i] = query(1,1,n,0, ind[b[i]])+1;
        update(1,1,n,ind[b[i]], dp[i]);
    }

    int ans = 0;

    for(int i = 1; i <= m; i++) ans = max(ans,dp[i]);

    cout << ans << "\n";
    

    

    


}