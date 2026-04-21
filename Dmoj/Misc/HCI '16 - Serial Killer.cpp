#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, st[MAXN<<2], dp[MAXN];

pair<int,int> a[MAXN];

void update(int node, int l, int r,int i, int x){
    if(l == r){
        st[node] = max(st[node], x);
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;

    return max(query(node<<1,l,mid,x,y), query(node<<1|1, mid+1,r,x,y));
}

/*
number line with objects of different heights 
choose smallest y that will work for each i

we can also forgo i entirely 

dp

sort by (x,y)
bsearch for next one we can transition to and then its standard dp

2 segtrees 

process by group of x and then add to segtree of heights when that group is done 
*/

int main(){
    cin >> n;

    int m = 1e5+5;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    


    sort(a+1, a+n+1);

    vector<pair<int,int>> q;

    for(int i = n; i >= 1; i--){
        

        //cout << a[i].first << " " << a[i].second << " " << query(1,1,m, a[i].second+1, m) << "\n";
        //tallest first
        dp[i] = query(1,1,m, a[i].second+1, m) + 1;

    
        q.push_back({a[i].second, dp[i]});

        if(a[i].first != a[i-1].first){
            for(auto [h, val] : q) update(1,1,m, h, val);
            q.clear();
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";



}