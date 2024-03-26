#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
 
//cses planetary queries I
 
const int MAXN = 2e5+5;
const int MAXD = 30; //log2(1e9)
 
int n,q, jmp[MAXN][MAXD], par[MAXN];
 
void pre(){
    for(int i = 1; i <= n; i++) jmp[i][0] = par[i];
    for(int i = 1; i < MAXD; i++){
        for(int j = 1; j <= n; j++) jmp[j][i] = jmp[jmp[j][i-1]][i-1];
    }
}
 
int query(int node, int d){
    for(int i = 0; i < MAXD; i++){
        if(d&(1<<i)) node = jmp[node][i]; 
    }
    return node;
}
 
 
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++) cin >> par[i];
 
    pre();
 
    while(q--){
        int x, i; cin >> x >> i;
 
        cout << query(x,i) << "\n";
    }
}