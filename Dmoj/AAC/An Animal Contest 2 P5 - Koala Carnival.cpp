#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, q, a[MAXN], cnt[MAXN], st[MAXN<<2][2], best[MAXN][2], last[MAXN];

//for each i compute the closest copy on the left and right
//or compute how far left and right you can go
//during query rmq for both sides 

void build(int node, int l, int r){
    if(l == r){
        st[node][0] = l-best[l][0]+1;
        st[node][1] = best[l][1];
        return;
    }

    int mid = (l+r)>>1; 
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node][0] = max(st[node<<1][0], st[node<<1|1][0]);
    st[node][1] = min(st[node<<1][1], st[node<<1|1][1]);
}

int queryl(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node][0];

    int mid = (l+r)>>1;
    return max(queryl(node<<1, l, mid, x,y), queryl(node<<1|1, mid+1,r,x,y)); 
}

int queryr(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node][1];

    int mid = (l+r)>>1;
    return min(queryr(node<<1, l, mid, x,y), queryr(node<<1|1, mid+1,r,x,y)); 
}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 0;

    for(int i = 1; i <= n; i++){
        l = max(l, last[a[i]]+1);
        last[a[i]] = i;
        best[i][0] = l;
    }

    fill(last+1, last+n+1, n+1);

    int r = n+1;

    for(int i = n; i >= 1; i--){
        r = min(r, last[a[i]]-1);
        last[a[i]] = i;
        best[i][1] = r;
    }

    build(1,1,n);

    int x = 0;

    while(q--){
        int l,r; cin >> l >> r;

        l ^= x;
        r ^= x;

        int ans = 0;
        int lo = r;
        int hi = n;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(best[mid][0] <= l){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        cout << (x = queryl(1,1,n,r,ans)) << "\n";
    }


    

}