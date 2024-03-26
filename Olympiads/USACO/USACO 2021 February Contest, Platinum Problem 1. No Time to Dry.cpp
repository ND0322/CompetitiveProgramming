#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;


int n, q, st[MAXN<<2], a[MAXN], ans[MAXN];

stack<int> mn;

vector<pair<pair<int,int>,int>> queries;

//subtract the number of pairs so that between them we can color with that color to connect them
//all the stuff in between has to be less

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1, mid+1,r,i,x);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;

    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1,l,mid,x,y) + query(node<<1|1,mid+1,r,x,y);
}


int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;

        queries.push_back({{r,l}, i});
    }

    sort(queries.begin(), queries.end());

    int i = 1;

    for(auto qu : queries){
        int l = qu.first.second;
        int r = qu.first.first;
        int id = qu.second;
        while(i <= r){
            while(mn.size() && a[mn.top()] > a[i]) mn.pop();
            if(mn.size() && a[mn.top()] == a[i]){
                update(1,1,n,mn.top(), 1);
                mn.pop();
            }
            mn.push(i);
            i++;
        }

        ans[id] = r-l+1 - query(1,1,n,l,r)USACO 2022 US Open Contest, Silver
Problem 1. Visits;
    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";


    


}