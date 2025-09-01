#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e9+7;
const int MAXQ = 2e5+5;

#define int long long

/*
find the maximum i such that 
# of 1s between [l:i] = k - r+cnt

precomp powers of 2 and do some math shit to calc

queries are offline

2p and sliding window

do rle and offline 2p stuff probably

for the suffix part just run a prefix sum and divide by 2^l

where l is the left of the suffix

might just use lazy sparse seg
*/

int cnt = 1, n, m ,q;

struct Node{
    int lz = 0, sm = 0, cnt = 0, full;

    Node *lc = nullptr, *rc = nullptr;
};

Node *rt = new Node;




int fastpow(int a, int b){
    long long ans = 1;
    while(b){
        if(b&1) ans = (ans*a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}


void pushdown(Node *node, int l, int r, int mid){
    if(!node->lz) return;
    if(node->lc == nullptr){
        node->lc = new Node();
        node->lc->full = (fastpow(2, mid - l + 1) - 1 + MOD) % MOD;
    }
    if(node->rc == nullptr){
        node->rc = new Node();
        node->rc->full = (fastpow(2, r-mid) - 1 + MOD) % MOD;
    }
    
    (node->lc)->lz ^= 1;
    (node->rc)->lz ^= 1;

    (node->lc)->cnt = (mid - l + 1) - (node->lc)->cnt;
    (node->rc)->cnt = (r-mid) - (node->rc)->cnt;

    (node->lc)->sm = ((fastpow(2, mid-l+1) + MOD - 1) % MOD - (node->lc)->sm + MOD) % MOD;
    (node->rc)->sm = ((fastpow(2, r-mid) + MOD - 1) % MOD - (node->rc)->sm + MOD) % MOD;
    node->lz = 0;
}


void update(Node *node, int l, int r, int x, int y){
    if(x > r || y < l ) return;
    if(x <= l && y >= r){
        node->lz ^= 1;
        node->cnt = r-l+1 - node->cnt;
        node->sm = (node->full % MOD - node->sm + MOD) % MOD;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    if(node->lc == nullptr){
        node->lc = new Node();
        node->lc->full = (fastpow(2, mid - l + 1) - 1 + MOD) % MOD;
    }
    if(node->rc == nullptr){
        node->rc = new Node();
        node->rc->full = (fastpow(2, r-mid) - 1 + MOD) % MOD;
    }
    update(node->lc, l, mid, x, y);
    update(node->rc, mid+1, r, x, y);
    node->cnt = (node->lc)->cnt + (node->rc)->cnt;
    node->sm = ((((node->lc)->sm * ((node->rc->full + 1) % MOD)) % MOD) + (node->rc)->sm) % MOD;
}

int qcnt(Node *node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return node->cnt;

    int mid = (l+r)>>1;
    if(node->lc == nullptr){
        node->lc = new Node();
        node->lc->full = (fastpow(2, mid - l + 1) - 1 + MOD) % MOD;
    }
    if(node->rc == nullptr){
        node->rc = new Node();
        node->rc->full = (fastpow(2, r-mid) - 1 + MOD) % MOD;
    }
    pushdown(node, l,r,mid);
    return qcnt(node->lc, l, mid, x,y) + qcnt(node->rc, mid+1,r,x,y);
}

int qsm(Node *node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return node->sm;

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return ((qsm(node->lc, l, mid, x, y) * ((node->rc->full + 1) % MOD)) % MOD + qsm(node->rc, mid+1,r,x,y)) % MOD;
}



int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;

    while(m--){
        int l,r; cin >> l >> r;

        update(rt,1,n, l, r);
    }

    while(q--){
        int l,r,k; cin >> l >> r >> k;

        if(qcnt(rt,1,n,l,r) >= k){
            cout << (fastpow(2,k) - 1 + MOD) % MOD << "\n";
            continue;
        }

        int lo = l-1;
        int hi = r;

        int i = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(qcnt(rt,1,n, l, mid) + r - mid >= k){
                lo = mid+1;
                i = mid;
            }
            else hi = mid-1;
        }

        int rs = qsm(rt,1,n,i+1, r) * fastpow(fastpow(2, n-r), MOD-2) % MOD;

        
        cout << ((((fastpow(2, qcnt(rt,1,n,l,i)) - 1 + MOD) % MOD) * fastpow(2, r-i)) % MOD + rs) % MOD<< "\n";
    }
    
}


