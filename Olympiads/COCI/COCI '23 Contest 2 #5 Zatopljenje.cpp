#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//solve offline sort by k descending 

//keep val l and r of a binary string in the st

const int MAXN = 2e5+5;

int n, q, ans[MAXN];

struct Node{
    int val;

    bool l, r;
} st[MAXN<<2];

pair<int,int> h[MAXN];
vector<pair<pair<int,int>,pair<int,int>>> queries;

Node comb(Node a, Node b){
    Node res;

    res.l = a.l;
    res.r = b.r;
    res.val = a.val + b.val - (a.r & b.l);
    return res;
}


void update(int node, int l, int r,int i){
    if(l == r){
        st[node].val = 1;
        st[node].l = 1;
        st[node].r = 1;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i);
    else update(node<<1|1, mid+1,r,i);
    st[node] = comb(st[node<<1], st[node<<1|1]);
    
}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l){
        Node tmp;
        tmp.l = 0;
        tmp.r = 0;
        tmp.val = 0;
        return tmp;
    }
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return comb(query(node<<1, l, mid, x, y),query(node<<1|1, mid+1, r, x, y));
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;


    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        h[i] = {x,i};
    }

    for(int i = 0; i < q; i++){
        int l,r,k; cin >> l >> r >> k;
        queries.push_back({{k,i}, {l,r}});
    }

    sort(h+1, h+n+1);
    sort(queries.rbegin(), queries.rend());

    reverse(h+1, h+n+1);
    


    int i = 1;

    for(pair<pair<int,int>,pair<int,int>> p : queries){
        while(i <= n && p.first.first < h[i].first){
            //cout << i <<" "<< h[i].first << " " << h[i].second << "\n";
            update(1,1,n,h[i].second);
            i++;
        }
        
        ans[p.first.second] = query(1,1,n, p.second.first, p.second.second).val;

    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";

}