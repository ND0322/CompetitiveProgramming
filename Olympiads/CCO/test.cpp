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
    int sm[2], lz[2], mn[2], mx[2];
} st[MAXN<<2];

inline void pushdown(int node, bool p) {
    if(!st[node].lz[p]) return;
    st[node<<1].lz[p] += st[node].lz[p];
    st[node<<1|1].lz[p] += st[node].lz[p];
    st[node<<1].mn[p] += st[node].lz[p];
    st[node<<1|1].mn[p] += st[node].lz[p];
    st[node<<1].mx[p] += st[node].lz[p];
    st[node<<1|1].mx[p] += st[node].lz[p];
    st[node].lz[p] = 0;
}

inline void update(int node, int l, int r, int i, int x) {
    if(l == r) {
        st[node].sm[0] = x;
        st[node].sm[1] = x;
        return;
    }
    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, x);
    else update(node<<1|1, mid+1, r, i, x);
    
    st[node].sm[0] = (st[node<<1].sm[0] + st[node<<1|1].sm[0]);
    if(st[node].sm[0] >= MOD) st[node].sm[0] -= MOD;
    st[node].sm[1] = (st[node<<1].sm[1] + st[node<<1|1].sm[1]);
    if(st[node].sm[1] >= MOD) st[node].sm[1] -= MOD;
}

inline void add(int node, int l, int r, int x, int y, int v, bool p) {
    if(x > r || y < l) return;
    if(x <= l && y >= r) {
        st[node].mn[p] += v;
        st[node].mx[p] += v;
        st[node].lz[p] += v;
        return;
    }
    pushdown(node, p);
    int mid = (l+r)>>1;
    add(node<<1, l, mid, x, y, v, p);
    add(node<<1|1, mid+1, r, x, y, v, p);
    
    st[node].mn[p] = min(st[node<<1].mn[p], st[node<<1|1].mn[p]);
    st[node].mx[p] = max(st[node<<1].mx[p], st[node<<1|1].mx[p]);
}

inline int query(int node, int l, int r, int x, int y, bool p) {
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) {
        if(st[node].mn[p] > 0) return 0;
        if(st[node].mx[p] <= 0) return st[node].sm[p];
    }
    pushdown(node, p);
    int mid = (l+r)>>1;
    int resp = query(node<<1, l, mid, x, y, p) + 
               query(node<<1|1, mid+1, r, x, y, p);
    return (resp >= MOD ? resp - MOD : resp);
}

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

    update(1, 1, n+1, n+1, 1);
    dp[n+1] = 1;

    for(int i = n; i >= 1; i--){
        bool p = i&1;
        
        if(sack[i][p] != n+1) add(1, 1, n+1, sack[i][p]+1, sack[sack[i][p]][p], -1, p);
        add(1, 1, n+1, i+1, sack[i][p], 1, p);
        //add(1, 1, n+1, r[i+1]+1, n+1, p);


        if(r[i+1] >= i+2 && sack[i][p] < r[i+1]) dp[i] = query(1, 1, n+1, i, r[i+1], p);
        
        if(r[i] >= i+2 && sack[i+1][!p] < r[i]) dp[i] += query(1, 1, n+1, i+2, r[i], !p);

        //interesting
        if(sack[i][p] < r[i+1] && sack[i+1][!p] < r[i]) cout << i << "\n";


        if(dp[i] >= MOD) dp[i] -= MOD;
        dp[i] += dp[i+1];
        if(dp[i] >= MOD) dp[i] -= MOD;

        update(1, 1, n+1, i, dp[i]);
    }

    cout << dp[1] << "\n";
    return 0;
}