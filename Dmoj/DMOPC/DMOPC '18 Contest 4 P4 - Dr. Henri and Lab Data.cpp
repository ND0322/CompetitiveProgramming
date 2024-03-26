#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, q;

pair<int,int> a[MAXN];

long long st[MAXN<<2], psa[MAXN], ans[MAXN];


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

long long query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return query(node<<1,l,mid, x,y) + query(node<<1|1,mid+1,r,x,y);
}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        psa[i] = psa[i-1] + x;
        a[i] = {x,i};
    }

    sort(a+1,a+n+1);

    vector<pair<pair<int,int>,pair<int,int>>> queries;

    for(int i = 0; i < q; i++){
        int l, r, k; cin >> l >> r >> k;

        queries.push_back({{k,i},{l,r}});
    }

    sort(queries.begin(), queries.end());

    int i = 1;

    for(auto qu : queries){
        auto [k,id] = qu.first;
        auto [l,r] = qu.second;

        while(i <= n && a[i].first < k){
            update(1,1,n,a[i].second, a[i].first);
            i++;
        }
        ans[id] =  psa[r] - psa[l-1] - 2 * query(1,1,n,l,r);
    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";

}