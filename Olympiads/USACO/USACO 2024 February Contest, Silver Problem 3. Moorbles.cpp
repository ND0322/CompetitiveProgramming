#include <bits/stdc++.h>
#include <iostream>
#include <map>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#define int long long


using namespace std;

const int MAXN = 3e5+5;

int n, m, k, a[MAXN][2][2], ans[MAXN], st[MAXN<<2], psa[MAXN];

void build(int node, int l, int r){
    if(l == r){
        st[node] = psa[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return min(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}
//im so fkn dumb

void solve(){
    cin >> n >> m >> k;
    memset(a,0,sizeof(a));
    memset(psa,0,sizeof(psa));
    for(int i = 1; i <= m; i++){

        a[i][0][0] = 1e9;
        a[i][1][0] = 1e9;

        for(int j = 0; j < k; j++){
            int x; cin >> x;

            

            a[i][x&1][0] = min(a[i][x&1][0],x);
            a[i][x&1][1] = max(a[i][x&1][1], x);
        }

        if(a[i][0][0] >= 1e9) a[i][0][0] = 0;
        if(a[i][1][0] >= 1e9) a[i][1][0] = 0;
    }

    for(int i = 1; i <= m; i++){
        psa[i] = max((!a[i][1][0] ? a[i][0][0] : -a[i][1][1]), (!a[i][0][0] ? a[i][1][0] : -a[i][0][1])) + psa[i-1];
    }

    build(1,1,m);
    int cur = n;
    for(int i = 1; i <= m; i++){
        //check if it is recoverable
        bool flag = (query(1,1,m,i+1, m) - psa[i] + cur + (!a[i][1][0] ? a[i][0][0] : -a[i][1][1])) > 0;

        if(flag && cur + (!a[i][1][0] ? a[i][0][0] : -a[i][1][1]) > 0){
            ans[i] = 0;
            cur += (!a[i][1][0] ? a[i][0][0] : -a[i][1][1]);
        }
        else{
            ans[i] = 1;
            cur += (!a[i][0][0] ? a[i][1][0] : -a[i][0][1]);
        }
    }

    cur = n;
    for(int i = 1; i <= m; i++){
        if(!ans[i]) cur += (!a[i][1][0] ? a[i][0][0] : -a[i][1][1]);
        else cur += (!a[i][0][0] ? a[i][1][0] : -a[i][0][1]);


        if(cur <= 0){
            cout << "-1\n";
            return;
        }
    }

    for(int i = 1; i < m; i++){
        cout << (ans[i] ? "Odd " : "Even ");
    }

    cout << (ans[m] ? "Odd" : "Even") << "\n";

}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}

//just partials and be patient