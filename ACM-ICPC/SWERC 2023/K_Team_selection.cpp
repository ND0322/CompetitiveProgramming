#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e6+5;

int n, st[MAXN<<2];

pair<int,bool> a[MAXN];

void build(int node, int l, int r){
    if(l == r){
        st[node] = 1;
        return;   
    }

    int mid = (l+r)>>1;
    build(node<<1, l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = st[node<<1] + st[node<<1|1];
}

void update(int node, int l, int r, int i){
    if(l == r){
        st[node] = 0;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1,l,mid,i);
    else update(node<<1|1,mid+1,r,i);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int k){
    if(l == r) return l;
    int mid = (l+r)>>1;

    if(st[node<<1] >= k) return query(node<<1,l,mid,k);
    return query(node<<1|1,mid+1,r,k - st[node<<1]);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    vector<vector<int>> ans(2,vector<int>());

    for(int i = 1; i <= n/2; i++){
        int x; cin >> x;

        a[i] = {x,0}; 
    }

    for(int i = n/2+1; i <= n; i++){
        int x; cin >> x;
        a[i] = {x,1};
    }

    vector<pair<int,bool>> upd;

    for(int i = 1; i <= n/2; i++){
        upd.push_back({a[i].first,0});
        upd.push_back({a[i+n/2].first,1});
    }

    build(1,1,n);

    for(auto [k,t] : upd){
        
        //cout << query(1,1,n,k) << "\n";
        ans[t].push_back(query(1,1,n,k));
        update(1,1,n,query(1,1,n,k));
    }
    

    for(int i : ans[0]) cout << i << " ";
    cout << "\n";
    for(int i : ans[1]) cout << i << " ";
    cout << "\n";

}
