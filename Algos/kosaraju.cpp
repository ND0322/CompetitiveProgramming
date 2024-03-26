#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

//never use this algo over tarjans

int n, m, comp[MAXN];

vector<int> adj[MAXN], adjRev[MAXN], order, cur;

bitset<MAXN> visited;

void topo(int node){
  visited[node] = true;

  for(int child:adj[node]){
     if(!visited[child]){
       topo(child);
     }
  }

  order.push_back(node);
}

void dfs(int node){
  visited[node] = true;
  cur.push_back(node);

  for(int child:adjRev[node]){
    if(!visited[child]){
      dfs(child);
    }
  }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adjRev[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) topo(i);
    }

    reverse(order.begin(), order.end());
    visited.reset();

    int cnt = 0;

    for(int i:order){
        if(!visited[i]){
            dfs(i);

            for(int j:cur) comp[j] = cnt;
            cnt++;
            cur.clear();


        }
    }

    cout << cnt << "\n";

    for(int i = 1; i <= n; i++) cout << comp[i]+1 << " ";

}