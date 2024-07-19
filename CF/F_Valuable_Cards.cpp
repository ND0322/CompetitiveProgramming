#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, dp[MAXN], a[MAXN], x, st[MAXN<<2];

//greedy dp?
//build freq array over pfacts to find the rightmost r for transition then simple seg query
//2p instead of bsearch

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > y || y < l) return 1e9;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return min(query(node<<1,l,mid,x,y),query(node<<1|1,mid+1,r,x,y));
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> x;



    }
}