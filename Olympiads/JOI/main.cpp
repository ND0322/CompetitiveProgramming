#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;


const int MAXN = 1e5+5;
const int MAXD = 17; 


int n,m,q, jmp[MAXN][MAXD], depth[MAXN], in[MAXN], out[MAXN], a[MAXN],last[MAXN], bit[MAXN], t;

pair<int,int> edges[MAXN];

vector<int> adj[MAXN];

bool built[MAXN];

void dfs(int node){

    a[node] = 1;
    in[node] = t++;
    
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adj[node]){
        if(jmp[node][0] == child) continue;
        depth[child] = depth[jmp[child][0] = node]+1;
        dfs(child);
    }

    out[node] = t;
}


void update(int i, int x){
    for(; i <= n; i += (i & -i)){
        cout << i << "\n";
        bit[i] += x;
    }
}

int query(int i){
    int ans = 0;
    for(; i > 0; i -= (i & -i)) ans += bit[i];
    return ans;
}

int find(int node){
    int ans = node;
    for(int i = MAXD; i >= 0; i--){
        if(jmp[ans][i] && query(in[jmp[ans][i]]) == query(in[node])) node = jmp[ans][i];
    }
    return ans;
}
int main(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;

        edges[i] = {x,y};
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    
    for(int i = 1; i <= n; i++){
        update(in[i], -1);
        update(out[i], 1);
    }

    /*


    //store information of a connected component in some node
    //lowest node using only active edges
    while(m--){
        int i; cin >> i;

        int x = edges[i].first;
        int y = edges[i].second;

        if(jmp[x][0] == y) swap(x,y);

        if(!built[i]){
            //split the component

            a[find(x)] += a[y] - last[y];

            //build

            update(in[y], 1);
            update(out[y], -1);
            built[i] = 1;
            
        }
        else{
            //sync up the crap

            a[y] = a[find(x)];
            last[y] = a[y];
            
            //delete this edge

            update(in[y],-1);
            update(out[y], 1);
            built[i] = 0;
        }
    }

    while(q--){
        int x; cin >> x;

        cout << a[find(x)] << "\n";
    }
    
    */
   
}