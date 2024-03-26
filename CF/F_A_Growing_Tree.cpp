#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n,q, in[MAXN], out[MAXN], t;

long long st[MAXN<<1];

vector<int> adj[MAXN];

void update(int l, int r, long long x){
    for(l += n, r+=n; l < r; l >>=1, r>>=1){
        if(l&1) st[l++] += x;
        if(r&1) st[--r] += x;
    }
}

long long query(int i){
    long long ans = 0;
    for(i += n; i > 0; i >>=1) ans += st[i];
    return ans;
}

void dfs(int node, int par){
    in[node] = t++;

    for(int child:adj[node]){
        if(child == par) continue;

        dfs(child, node);
    }
    out[node] = t;
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> q;

        t = 0;

        n = 1;

        vector<pair<int,pair<int,int>>> queries;

        for(int i = 0; i < q; i++){
            int typ; cin >> typ;

            if(typ == 2){
                int v,x; cin >> v >> x;

                queries.push_back({2,{v,x}});
            }
            else{
                n++;
                int v; cin >> v;
                queries.push_back({1,{n,v}});
            }
        }

        for(int i = 0; i <= 2*n; i++) st[i] = 0;
        for(int i = 1; i <= n; i++) adj[i].clear();

        
        for(pair<int,pair<int,int>> p : queries){
            if(p.first == 1){
                adj[p.second.first].push_back(p.second.second);
                adj[p.second.second].push_back(p.second.first);
            }
        }
    

        dfs(1, -1);

        for(pair<int,pair<int,int>> p : queries){
            if(p.first == 1) update(in[p.second.first], in[p.second.first]+1,-query(in[p.second.first]));
            else update(in[p.second.first], out[p.second.first], p.second.second);
        }

        for(int i = 1; i <= n; i++) cout << query(in[i]) << " ";
        cout << "\n";

        

    }
}