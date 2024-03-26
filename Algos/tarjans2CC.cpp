#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n,m,disc[MAXN],low[MAXN],cnt,t;

bool in[MAXN];

stack<int> st;

vector<int> adj[MAXN],comps[MAXN];

//solving
//https://judge.yosupo.jp/problem/two_edge_connected_components

void tarjans(int node,int par){
    disc[node] = low[node] = ++t;
    

    in[node] = 1;
  
    st.push(node);

    for(int child:adj[node]){

        
        if(child == par){
            par = -1;
            continue;
        }

        if(!disc[child]){
            tarjans(child,node);

            low[node] = min(low[node],low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node],disc[child]);
        }
    }

    if(low[node] == disc[node]){
        while(st.top() != node){
            
            comps[cnt].push_back(st.top());
            in[st.top()] = 0;
            st.pop();
        }

        
        comps[cnt].push_back(node);
        in[node] = 0;
        st.pop();

        cnt++;
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 0; i < n; i++){
        if(!disc[i]) tarjans(i,-1);
    }

    cout << cnt << "\n";

    for(int i = 0; i < cnt; i++){
        cout << comps[i].size() << " ";
        for(int j:comps[i]) cout << j << " ";
        cout << "\n";
    }
}



