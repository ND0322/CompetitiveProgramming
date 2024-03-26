#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

const int MAXN = 1e5+5;

int n,q, st[MAXN<<1], ans[MAXN];

pair<int,int> a[MAXN];
vector<pair<pair<int,int>,pair<int,int>>> queries;

void update(int i, int x){
    for(st[i+=n] = x; i > 1; i>>=1) st[i>>1] = st[i] + st[i^1];
}

int query(int l, int r){
    int ans = 0;
    for(l += n, r += n; l < r; l >>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a[i] = {x,i};
    }

    sort(a+1, a+n+1);
    reverse(a+1,a+n+1);
    cin >> q;

    for(int i = 0; i < q; i++){
        int l,r,k; cin >> l >> r >> k;
        queries.push_back({{k,i},{l,r}});
    }

    sort(queries.rbegin(), queries.rend());

    int i = 1;
    for(pair<pair<int,int>,pair<int,int>> p : queries){
        while(i <= n && a[i].first >= p.first.first){
            update(a[i].second-1, a[i].first);
            i++;
        }

        ans[p.first.second] = query(p.second.first, p.second.second+1);
    }

    for(int i = 0; i < q; i++) cout << ans[i] << "\n";



}