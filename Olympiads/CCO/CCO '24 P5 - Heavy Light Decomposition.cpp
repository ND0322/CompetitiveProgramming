#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("bmi2,popcnt,lzcnt,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

static const int MAXN = 5e5+5;
static const int MOD = 1e6+3;

int n, dp[MAXN], a[MAXN], sack[MAXN][2], r[MAXN], last[MAXN][2];

struct Node {
    int sm, lz;
};

struct Segtree{
    Node st[MAXN<<2];

    void update(int node, int l, int r, int i, int x){
        if(l == r){
            st[node].sm = x;
            return;
        }

        int mid = (l+r)>>1;
        if(i <= mid) update(node<<1, l, mid, i , x);
        else update(node<<1|1, mid+1,r,i,x);

        st[node].sm = (st[node<<1].sm * (!st[node<<1].lz) + st[node<<1|1].sm * (!st[node<<1|1].lz)) % MOD;
    }

    void add(int node, int l, int r, int x, int y, int v){
        if(x > r || y < l) return;
        if(x <= l && y >= r){
            st[node].lz += v;
            return;
        } 

        int mid = (l+r)>>1;
        add(node<<1, l, mid, x, y, v);
        add(node<<1|1, mid+1,r,x,y,v);
        st[node].sm = (st[node<<1].sm * (!st[node<<1].lz) + st[node<<1|1].sm * (!st[node<<1|1].lz)) % MOD;
    }

    int query(){return st[1].sm * (!st[1].lz);}
} st[2];



int main() {
    scan(n);
    for(int i = 1; i <= n; i++) scan(a[i]);

    for(int i = 1; i <= n; i++) last[i][0] = last[i][1] = n+1;
    
    for(int i = n; i >= 1; i--){
        sack[i][0] = last[a[i]][0];
        sack[i][1] = last[a[i]][1];
        last[a[i]][i&1] = i;
    }

    r[n] = n+1;
    r[n+1] = n+1;
    for(int i = n-1; i >= 1; i--) r[i] = min({sack[i][0], sack[i][1], sack[i+1][i&1], r[i+2]});

    st[0].update(1, 1, n+1, n+1, 1);
    st[1].update(1, 1, n+1, n+1, 1);
    dp[n+1] = 1;

    for(int i = n; i >= 1; i--){
        bool p = i&1;
        
        if(sack[i][p] != n+1) st[p].add(1, 1, n+1, sack[i][p]+1, sack[sack[i][p]][p], -1);
        st[p].add(1, 1, n+1, i+1, sack[i][p], 1);
        st[p].add(1, 1, n+1, r[i+1]+1, n+1, 1);
        st[!p].add(1, 1, n+1, r[i]+1, n+1, 1);


        dp[i] = st[p].query();
        
        
       
        st[!p].add(1,1,n+1, i+1, i+1, 1);
        dp[i] += st[!p].query();
        st[!p].add(1,1,n+1, i+1, i+1, -1);
        

        if(dp[i] >= MOD) dp[i] -= MOD;
        dp[i] += dp[i+1];
        if(dp[i] >= MOD) dp[i] -= MOD;

        st[0].update(1, 1, n+1, i, dp[i]);
        st[1].update(1, 1, n+1, i, dp[i]);
    }

    cout << dp[1] << "\n";
    return 0;
}