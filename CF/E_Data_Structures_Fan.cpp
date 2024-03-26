#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

#define int long long
int n, q, a[MAXN];

string s;


struct Node{
    long long lz;
    long long state[2];

    Node(){
        state[0] = state[1] = lz = 0;
    }
} st[MAXN<<2];

void pushdown(int node, int l, int r){
    if(st[node].lz){
        swap(st[node].state[0], st[node].state[1]);

        if(l != r){
            st[node<<1].lz ^= 1;
            st[node<<1|1].lz ^= 1;
        }

        st[node].lz = 0;
    }
}

void build(int node, int l, int r){
    if(l == r){
        int tmp =(int)(s[l-1]-'0');
        st[node].state[tmp] = a[l];
        st[node].state[tmp^1] = 0;
        st[node].lz = 0;
        return;
    }


    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1, mid+1,r);
    st[node].state[0] = st[node<<1].state[0] ^ st[node<<1|1].state[0];
    st[node].state[1] = st[node<<1].state[1] ^ st[node<<1|1].state[1];
}

void update(int node, int l, int r, int x, int y){
    pushdown(node,l,r);
    if(x > r || y < l) return;

    if(x <= l && y >= r){

        swap(st[node].state[0], st[node].state[1]);

        if(l != r){
            st[node<<1].lz ^= 1;
            st[node<<1|1].lz ^= 1;
        }

        st[node].lz = 0;
        return;
    }

    int mid = (l+r)>>1;
    update(node<<1, l, mid, x, y);
    update(node<<1|1, mid+1, r, x, y);
    st[node].state[0] = st[node<<1].state[0] ^ st[node<<1|1].state[0];
    st[node].state[1] = st[node<<1].state[1] ^ st[node<<1|1].state[1];
}

long long query(int node, int l, int r, int x, int y, int k){
    pushdown(node,l,r);
    if(x > r || y < k) return 0;
    if(x <= l && y >= r) return st[node].state[k];

    int mid = (l+r)>>1;
    return query(node<<1, l,mid, x,y,k) ^ query(node<<1|1, mid+1, r, x,y,k);
}

int32_t main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        for(int i = 0; i <= n<<2; i++) st[i].state[0] = st[i].state[1] = st[i].lz = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        cin >> s;

        build(1,1,n);
        cin >> q;

        while(q--){
            int t; cin >> t;


            if(t == 1){
                int l, r; cin >> l >> r;

                update(1,1,n,l,r);
            }
            else{
                int x; cin >> x;

                cout << query(1,1,n,1,n,x) << " ";
            }
        }

        cout << "\n";
    }
    
}