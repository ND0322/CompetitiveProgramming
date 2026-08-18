#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

struct Node{
    int cnt;
    int sm;
} st[MAXN<<2];


void build(int node, int l, int r){
    if(l == r){
        st[node].cnt = 0;
        st[node].sm = 0;
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l, mid);
    build(node<<1|1, mid+1,r);
    st[node].cnt = 0;
    st[node].sm = 0;
    
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].cnt++;
        st[node].sm = x;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) update(node<<1,l , mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    st[node].cnt = st[node<<1].cnt + st[node<<1|1].cnt;
    st[node].sm = st[node<<1].sm + st[node<<1|1].sm;
}



int query(int node, int l, int r, int k) {
    if(st[node].sm < k) return -1;
    if(l == r) return 1;

    int mid = (l+r)>>1;
    int rsm = st[node<<1|1].sm;

    if(rsm >= k) return query(node<<1|1, mid + 1, r, k);
    
    int lcnt = query(node<<1, l, mid, k - rsm);
    return st[node<<1|1].cnt + lcnt;
    
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> v(n+1);
        vector<vector<int>> a(n+1, vector<int>(m+1));
        vector<vector<int>> mp(n+1, vector<int>(m+1));
        

        //obviously upperbounded by m

        for(int i = 1; i <= n; i++) cin >> v[i];

        vector<pair<int,pair<int,int>>> vals;
        
        build(1,1,n*m);

        vals.push_back({0, {0,0}});

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                vals.push_back({a[i][j], {i,j}});
            }
        }

        sort(vals.begin(), vals.end());

        for(int i = 1; i <= n * m; i++) mp[vals[i].second.first][vals[i].second.second] = i;
        
        int ans = m;
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= m; j++) update(1,1, n*m, mp[i][j], a[i][j]);



            int res = query(1,1,n*m,v[i]);

            if(res != -1) ans = min(ans, res);
        }

        cout << ans << "\n";




        
    }
}