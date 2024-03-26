#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e6+5;

int n,q, comp[MAXN], cur, a[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN];

//probably better way to count cycles but im lazy
void dfs(int node){
    vis[node] = 1;
    comp[node] = cur;
    for(int child : adj[node]){
        if(!vis[child]) dfs(child);
    }
}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        //ik u dont need this but im lazy ok
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            cur++;
        }
    }

    //check if a[i] is included in the set
    //if not add one

    
    while(q--){
        set<int> comps;
        set<int> nodes;

        int num; cin >> num;

        for(int i = 0; i < num; i++){
            int x; cin >> x;
            nodes.insert(x);
            comps.insert(comp[x]);
        }

        int ans = cur;

        //cout << comps.size() << "\n";

        ans -= comps.size();

        for(int i : nodes) ans += (nodes.find(a[i]) == nodes.end());

        cout << ans << "\n";


    }




}

