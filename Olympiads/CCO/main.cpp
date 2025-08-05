#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("bmi2,popcnt,lzcnt,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

static const int MAXN = 5e5+5;
static const int MOD = 1e6+3;

int n, dp[MAXN], a[MAXN], sack[MAXN][2], last[MAXN][2];


struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
};



struct Seg {
    Node st[MAXN << 2];

    void pushdown(int node, int l, int r, int mid) {
        if (st[node].lzSet) {
            st[node << 1].lzSet = st[node << 1 | 1].lzSet = st[node].lzSet % MOD;
            st[node << 1].lzAdd = st[node << 1 | 1].lzAdd = 0;
            st[node << 1].mn = st[node << 1 | 1].mn = st[node].lzSet % MOD;
            st[node << 1].mx = st[node << 1 | 1].mx = st[node].lzSet % MOD;

            if (l != r) {
                st[node << 1].sum = (st[node].lzSet % MOD) * (mid - l + 1) % MOD;
                st[node << 1 | 1].sum = (st[node].lzSet % MOD) * (r - mid) % MOD;
            }
        }

        if (st[node].lzAdd) {
            st[node << 1].lzAdd = (st[node << 1].lzAdd + st[node].lzAdd) % MOD;
            st[node << 1 | 1].lzAdd = (st[node << 1 | 1].lzAdd + st[node].lzAdd) % MOD;
            st[node << 1].mn = (st[node << 1].mn + st[node].lzAdd) % MOD;
            st[node << 1 | 1].mn = (st[node << 1 | 1].mn + st[node].lzAdd) % MOD;
            st[node << 1].mx = (st[node << 1].mx + st[node].lzAdd) % MOD;
            st[node << 1 | 1].mx = (st[node << 1 | 1].mx + st[node].lzAdd) % MOD;
            if (l != r) {
                st[node << 1].sum = (st[node << 1].sum + st[node].lzAdd * (mid - l + 1)) % MOD;
                st[node << 1 | 1].sum = (st[node << 1 | 1].sum + st[node].lzAdd * (r - mid)) % MOD;
            }
        }

        st[node].lzAdd = 0;
        st[node].lzSet = 0;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            st[node].mn = a[l] % MOD;
            st[node].sum = a[l] % MOD;
            st[node].mx = a[l] % MOD;
            return;
        }

        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        st[node].mn = min(st[node << 1].mn, st[node << 1 | 1].mn) % MOD;
        st[node].mx = max(st[node << 1].mx, st[node << 1 | 1].mx) % MOD;
        st[node].sum = (st[node << 1].sum + st[node << 1 | 1].sum) % MOD;
    }

    void add(int node, int l, int r, int x, int y, long long v) {
        if (x > r || y < l) return;
        if (x <= l && y >= r) {
            st[node].mn = (st[node].mn + v) % MOD;
            st[node].mx = (st[node].mx + v) % MOD;
            st[node].sum = (st[node].sum + (r - l + 1) * v) % MOD;
            st[node].lzAdd = (st[node].lzAdd + v) % MOD;
            return;
        }

        int mid = (l + r) >> 1;
        pushdown(node, l, r, mid);
        add(node << 1, l, mid, x, y, v % MOD);
        add(node << 1 | 1, mid + 1, r, x, y, v % MOD);
        st[node].mn = min(st[node << 1].mn, st[node << 1 | 1].mn) % MOD;
        st[node].mx = max(st[node << 1].mx, st[node << 1 | 1].mx) % MOD;
        st[node].sum = (st[node << 1].sum + st[node << 1 | 1].sum) % MOD;
    }

    void update(int node, int l, int r, int x, int y, long long v) {
        if (x > r || y < l) return;
        if (x <= l && y >= r) {
            st[node].mn = v % MOD;
            st[node].mx = v % MOD;
            st[node].sum = (r - l + 1) * v % MOD;
            st[node].lzAdd = 0;
            st[node].lzSet = v % MOD;
            return;
        }

        int mid = (l + r) >> 1;
        pushdown(node, l, r, mid);
        update(node << 1, l, mid, x, y, v % MOD);
        update(node << 1 | 1, mid + 1, r, x, y, v % MOD);
        st[node].mn = min(st[node << 1].mn, st[node << 1 | 1].mn) % MOD;
        st[node].mx = max(st[node << 1].mx, st[node << 1 | 1].mx) % MOD;
        st[node].sum = (st[node << 1].sum + st[node << 1 | 1].sum) % MOD;
    }

    long long qmn(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 1e18;
        if (x <= l && y >= r) return st[node].mn % MOD;
        int mid = (l + r) >> 1;
        pushdown(node, l, r, mid);
        return min(qmn(node << 1, l, mid, x, y), qmn(node << 1 | 1, mid + 1, r, x, y)) % MOD;
    }

    long long qmx(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return -1e18;
        if (x <= l && y >= r) return st[node].mx % MOD;
        int mid = (l + r) >> 1;
        pushdown(node, l, r, mid);
        return max(qmx(node << 1, l, mid, x, y), qmx(node << 1 | 1, mid + 1, r, x, y)) % MOD;
    }

    long long qsm(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && y >= r) return st[node].sum % MOD;
        int mid = (l + r) >> 1;
        pushdown(node, l, r, mid);
        return (qsm(node << 1, l, mid, x, y) + qsm(node << 1 | 1, mid + 1, r, x, y)) % MOD;
    }
} st[2];




int main() {
    scan(n);
    for(int i = 1; i <= n; i++) scan(a[i]);

    
    for(int i = 1; i <= n; i++){
        sack[i][0] = last[a[i]][0];
        sack[i][1] = last[a[i]][1];
        last[a[i]][i&1] = i;
    }

    for(int i = 1; i <= n; i++) cout << sack[i][0] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << sack[i][1] << " ";
    cout << "\n";

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int p = 0; p < 2; p++){
            if((i&1) != p){
                st[p].add(1,1,n,1, max(sack[i][0], sack[i][1]), 1);
                st[p].update(1,1,n, i,i, dp[i-1]);
                dp[i] += st[p].qsm(1,1,n, 1, n);

                if(i == 1) cout << p << " " << dp[i] << "\n";
            }
            else{
                st[p].add(1,1,n,1,sack[i][!p], 1);
                if(sack[i][p]){
                    st[p].add(1,1,n, sack[sack[i][p]][p]+1, sack[i][p], -1);
                    st[p].update(1,1,n, sack[i][p], sack[i][p], dp[sack[i][p]-1]);
                    
                } 
                

                st[p].add(1,1,n,sack[i][p]+1, i, 1);
                dp[i] += st[p].qsm(1,1,n,1,n); 

                if(i == 1) cout << p << " " << dp[i] << "\n";
            }
        }

        cout << dp[i] << "\n";

       
    }

    cout << dp[n] << "\n";
    return 0;
}