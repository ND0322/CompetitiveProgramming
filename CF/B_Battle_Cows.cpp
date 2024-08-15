#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, a[MAXN], st[MAXN<<1];


//try all i < k
//if a[k] < pmax at i womp womp
//bsearch with segtree

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1; 
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return max(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        int mn = 1e9;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mn = min(mn, a[i]);

            update(1,1,n,i,a[i]);
        }


        int ans = 0;
        for(int i = 1; i <= n; i++){
            update(1,1,n,k,a[i]);
            update(1,1,n,i, a[k]);

            if(query(1,1,n,1,i-1) > a[k]){
                update(1,1,n,i,a[i]);
                update(1,1,n,k, a[k]);
                continue;
            }

            int lo = i+1;
            int hi = n;

            int best = 0;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(query(1,1,n,i+1,mid) < a[k]){
                    lo = mid+1;
                    best = mid;
                }
                else hi = mid-1;
            }

            ans = max(ans, best - i + (i!=1));

            update(1,1,n,i,a[i]);
            update(1,1,n,k, a[k]);
        }

        cout << ans << "\n";
    }
}