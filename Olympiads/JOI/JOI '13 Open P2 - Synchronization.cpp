#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;


const int MAXN = 1e5+5;
const int MAXD = 17; 


int n,m,q, jmp[MAXN][MAXD], in[MAXN], out[MAXN], a[MAXN],last[MAXN], bit[MAXN], t = 1;

pair<int,int> edges[MAXN];

vector<int> adj[MAXN];

bool built[MAXN];

void dfs(int node){
    in[node] = t++;
    
    for(int i = 1; i < MAXD; i++) jmp[node][i] = jmp[jmp[node][i-1]][i-1];

    for(int child : adj[node]){
        if(jmp[node][0] == child) continue;
        jmp[child][0] = node;
        dfs(child);
    }

    out[node] = t;
}


void update(int i, int x){
    for(; i <= n; i += (i & -i)) bit[i] += x;
}

int query(int i){
    int ans = 0;
    for(; i > 0; i -= (i & -i)) ans += bit[i];
    return ans;
}

int find(int node){
    int ans = node;
    //bald me
    for(int i = MAXD-1; i >= 0; i--){
        if(jmp[ans][i] && query(in[jmp[ans][i]]) == query(in[node])) ans = jmp[ans][i];
    }
    return ans;
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;

    for(int i = 1; i < n; i++){
        int x,y; cin >> x >> y;

        edges[i] = {x,y};
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    
    for(int i = 1; i <= n; i++){
        a[i] = 1;
        update(in[i], -1);
        update(out[i], 1);
    }




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
    //for(int i = 1; i <= n; i++) cout << a[i] << "\n";
    while(q--){
        int x; cin >> x;

        //cout << find(x) << "\n";

        cout << a[find(x)] << "\n";

       
    }
    
    
   
}