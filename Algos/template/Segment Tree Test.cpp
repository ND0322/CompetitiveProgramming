#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

//recursive for g and q iterative for rmq

int n,q, rmq[MAXN<<1], st[MAXN<<2], rst[MAXN<<2];

int gcd(int a, int b){
    return (!b ? a : gcd(b, a%b));
}

void pushUp(int ind, int )

void build1(){
    for(int i = n-1; i > 0; i--) st[i] = min(st[i<<1], st[i<<1|1]);
}




void update1(int i, int x){
    for(rmq[i += n] = x; i > 1; i >>= 1) rmq[i>>1] = min(rmq[i], rmq[i^1]);
}

int query1(int l, int r){
    int ans = 1e9;

    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l&1) ans = min(ans,rmq[l++]);
        if(r&1) ans = min(ans,rmq[--r]);
    }

    return ans;
}

