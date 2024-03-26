#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int M = 65;

typedef long long ll;
//m is max length = should be log2(1e18) = ~60

//represent all paints x and y in binary
//any number affected by the paint will share a common suffix
//use trie to query

int n,q, tot = 1;

ll tr[MAXN*M*2][2], sum[MAXN*M*2];

int msb(ll x){
    return 64-__builtin_clzll(x);
}

void update(ll x, ll y, int val){

    
    int u = 1;
    int t;

    for(int i = 0; i < msb(x)-1; i++) {
        t = (x>>i)&1;
        if(!tr[u][t]) tr[u][t] = ++tot;
        u = tr[u][t];
    }

        
        
    if(!sum[u]) sum[u]= ++tot; 

    u = sum[u];

    for(int i = 0; i < msb(y)-1; i++){
        t = (y>>i)&1;
        if(!tr[u][t]) tr[u][t] = ++tot;
        u = tr[u][t];
    }
    
        
     sum[u] += val;
    
}

int query(ll x, ll y){

    
    int ans = 0;

    int u = 1;
    
    for(int i = 0; u && i < msb(x); i++){
        
        
        int v = sum[u];

        for(int j = 0; v && j < msb(y); j++){
            ans += sum[v];
            v = tr[v][(y>>j)&1];
        }

        u = tr[u][(x>>i)&1];
    }

    return ans;
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> q;

    while(n--){
        ll x,y; 
        int c;
        cin >> x >> y >> c;

        update(x,y,c);
    }

    while(q--){
        ll x,y; cin >> x >> y;

        cout << query(x,y) << "\n";
    }
}