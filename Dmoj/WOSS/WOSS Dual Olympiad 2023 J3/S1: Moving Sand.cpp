//solving cses subtree queries

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, q;

long long st[MAXN<<1], a[MAXN];

vector<int> adj[MAXN];



void build(){
    for(int i = n-1; i > 0; i--) st[i] = st[i>>1] + st[i>>1|1];
}

void update(int i, int x){
    for(st[i+=n] = x; i > 1; i>>=1) st[i>>1] = st[i] + st[i^1];
}

long long query(int l, int r){
    long long ans = 0;

    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }

    return ans;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        update(i,x);
    }

   

    

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int i, x; cin >> i >> x;

            i--;

            update(i,query(i,i+1) - x);
            update(i-1, query(i-1,i) + x);
        }

        if(t == 2){
            int i, x; cin >> i >> x;

            i--;

            update(i,query(i,i+1) - x);
            update(i+1, query(i+1,i+2) + x);
        }
        
        if(t == 3){
            int l, r; cin >> l >> r;

            //cout << l-1 << " " << r << "\n";
           
            cout << query(l-1, r) << "\n";


        }
    }
}

