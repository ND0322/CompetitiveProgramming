#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

#define int long long

using namespace std;

const int MAXN = 1e5+5;

int n, m;

long long st[MAXN*64][2];

vector<int> coord;

pair<pair<int,int>,pair<int,int>> a[MAXN];

//n^2
//for some filter have dpl representing path to 0 and dpr representing path to 1
//we look for some thing within this range we jump from
//update dp state as the position of the out part of the filter

//full just throw a sparse seg tree over that sh
//nvm sparse dont work coord compress

void update(int node, int l, int r, int i, long long x, bool t){
    if(l == r){

        st[node][t] = min(st[node][t], x);
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x,t);
    else update(node<<1|1, mid+1,r,i,x,t);
    

    st[node][t] = min(st[node<<1][t], st[node<<1|1][t]);
}

long long query(int node, int l, int r, int x, int y, bool t){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node][t];
    int mid = (l+r)>>1;
    return min(query(node<<1, l,mid, x, y, t), query(node<<1|1, mid+1,r,x,y,t));
}

int get(int x){
    return (int)(lower_bound(coord.begin(), coord.end(), x) - coord.begin())+1;
}

int32_t main(){
    cin >> n >> m;

    coord.push_back(1);
    coord.push_back(m);

    for(int i = 1; i <= n; i++){
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;

        coord.push_back(a[i].first.first);
        coord.push_back(a[i].first.second);
        coord.push_back(a[i].second.first);
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    memset(st, 0x3f, sizeof(st));

    int tmp = m;

    m = coord.size();

    update(1,1,m,get(1), 0, 0);
    update(1,1,m,get(tmp),0,1);

    //cout << query(1,1,m, 1, 3, 0) << "\n";

    long long ans = 1e18;

    for(int i = 1; i <= n; i++){
        auto [l,r] = a[i].first;

        l = get(l);
        r = get(r);

        

        long long x = query(1,1,m,l,r,0) + a[i].second.second;
        long long y = query(1,1,m,l,r,1) + a[i].second.second;

        //cout << l << " " << r << " " << x << " " << y << "\n";


        ans = min(ans, x + y - a[i].second.second);
        update(1,1,m,get(a[i].second.first), x, 0);
        update(1,1,m,get(a[i].second.first), y, 1);
    }

    cout << (ans >= 1e18 ? -1 : ans) << "\n";
}




