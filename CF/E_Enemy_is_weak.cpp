#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>

#define int long long

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 1e6+5;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

typedef long long ll;

int n, cnt = 1, suf[MAXN], a[MAXN];

ll st[MAXN<<2];

ost s;

map<int,int> mp;

//intended is to coord compress but 🐒

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1,mid+1,r,i, x);
    st[node] = st[node<<1] + st[node<<1|1];
}

ll query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return query(node<<1,l,mid,x,y) + query(node<<1|1,mid+1,r,x,y);
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]] = 0;
    }

    int i = 0;

    for(auto j : mp) mp[j.first] = i++;

    s.insert(a[n]);

    for(int i = n-1; i >= 1; i--){
        suf[i] = s.order_of_key(a[i]);
        s.insert(a[i]);
    }


    long long ans = 0;
    for(int i = n; i >= 1; i--){
        ans += query(1,1,n, 0, mp[a[i]]);
        update(1,1,n, mp[a[i]], suf[i]);
    }

    cout << ans << "\n";




}