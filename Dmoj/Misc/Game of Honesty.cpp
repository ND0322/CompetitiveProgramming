#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 1e6+5;
const int MAXM = 3e4+5;


int n,m, st[MAXN<<2];

pair<int,pair<int,int>> queries[MAXM];

/*
query max along prefix l of r 
union all previous ranges to check for the one corner case 

*/

void build(int node, int l, int r){
    if(l == r){
        st[node] = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1, r);
    st[node] = max(st[node<<1], st[node<<1|1]);
}


inline void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}


inline int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return max(query(node<<1, l, mid, x, y), query(node<<1|1, mid+1,r,x,y));
}





inline bool f(int x){
    map<int, vector<pair<int,int>>, greater<int>> mp;
    set<pair<int,int>> uni;

    build(1,1,n);
    for(int i = 1; i <= x; i++) mp[queries[i].first].push_back(queries[i].second);

    for(auto [a, b] : mp){
        sort(b.begin(), b.end());

        auto [l,r] = b[0];

        for(int i = 1; i < b.size(); i++){
            if(r+1< b[i].first) return 0;
            l = max(l, b[i].first);
            r = min(r, b[i].second);
        }



        if(query(1,1,n, 1, l) >= r) return 0;


        l = b[0].first;
        r = b[0].second;

        for(int i = 1; i < b.size(); i++){
            if(r +1 < b[i].first) return 0;
            r = max(r, b[i].second);
        }

        
        update(1,1,n, l, max(query(1,1,n, l,r+1), r));
    }

    return 1;
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= m; i++) cin >> queries[i].second.first >> queries[i].second.second >> queries[i].first;

    int lo = 1;
    int hi = m;

    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(!f(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }
    cout << ans << "\n";
}