#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

pair<int,int> nxt[MAXN];

struct Node{
    int mn, lz;
} st[MAXN<<2];

void pushdown(int node){
    if(!st[node].lz) return;
    st[node<<1].lz = st[node<<1|1].lz = st[node].lz;
    st[node<<1].mn = st[node<<1|1].mn = st[node].lz;

    st[node].lz = 0;
}

void update(int node, int l, int r, int x, int y, int v){
    if(x > r || y < l) return;

    if(x <= l && y >= r){
        st[node].mn = v;
        st[node].lz = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node);
    update(node<<1, l, mid, x, y, v);
    update(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node].mn;
    int mid = (l+r)>>1;
    pushdown(node);
    return min(query(node<<1,l,mid, x,y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    stack<pair<int,int>> st;

    st.push({0,0});

    for(int i = 1; i <= n; i++){
        while(a[i] <= st.top().first) st.pop();
        nxt[i].first = st.top().second;
        st.push({a[i], i});
    }

    while(st.size()) st.pop();

    st.push({0, n+1});

    for(int i = n; i >= 1; i--){
        while(a[i] <= st.top().first) st.pop();
        nxt[i].second = st.top().second;
        st.push({a[i], i});
    }

    map<int,int> lengths;

    for(int i = 1; i <= n; i++) lengths[a[i]] = max(lengths[a[i]], nxt[i].second - nxt[i].first - 1);
    


    for(auto i : lengths) update(1,1,n, 1,  i.second, i.first);
    for(int i = 1; i <= n; i++) cout << query(1,1,n, i,i) << " ";
    cout << "\n";



    
}

