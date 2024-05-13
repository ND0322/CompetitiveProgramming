#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

//values only ever decrease
//take the max value at all times
//segtree to find max and index taking rightmost maximum + suffix updates

const int MAXN = 3e5+5;

int n;

struct Node{
    int mx, lz, id;
} st[MAXN<<2];

Node comb(Node x, Node y){
    Node ans;
    pair<int,int> tmp = max(make_pair(x.mx,x.id), make_pair(y.mx,y.id));
    ans.mx = tmp.first;
    ans.id = tmp.second;
    return ans;
}

void pushdown(int node){
    if(!st[node].lz) return;

    st[node<<1].lz += st[node].lz;
    st[node<<1|1].lz += st[node].lz;
    st[node<<1].mx += st[node].lz;
    st[node<<1|1].mx += st[node].lz;
    st[node].lz = 0;
}

void build(int node, int l, int r){
    st[node].lz = 0;
    if(l == r){
        int x; cin >> x;

        st[node].mx = x+l;
        st[node].id = -l;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node].mx = comb(st[node<<1], st[node<<1|1]).mx;
    st[node].id = comb(st[node<<1], st[node<<1|1]).id;
}

void update(int node, int l, int r, int x, int y, int v){
    pushdown(node);
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mx += v;
        st[node].lz += v;
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1, l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].mx = comb(st[node<<1], st[node<<1|1]).mx;
    st[node].id = comb(st[node<<1], st[node<<1|1]).id;   
}

pair<int,int> query(int node, int l, int r, int x, int y){
    pushdown(node);
    if(x > r || y < l) return {-1,-1};
    if(x <= l && y >= r) return {st[node].mx, st[node].id};
    
    int mid = (l+r)>>1;
    return max(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}


set<int,greater<int>> s;



int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        s.clear();

        build(1,1,n);

        for(int i = 1; i <= n; i++){
            auto [x,id] = query(1,1,n,1,n);
            id = -id;
            //cout << x << " " << id << "\n";
            s.insert(x);
            update(1,1,n,id,id,-1e18);
            update(1,1,n,id,n,-1);
        }

        
        
        for(int i : s) cout << i << " ";
        cout << "\n";
    }
}