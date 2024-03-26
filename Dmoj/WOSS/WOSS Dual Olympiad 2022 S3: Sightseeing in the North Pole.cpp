#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n,m,disc[MAXN],low[MAXN],cnt,t, comp[MAXN], sz[MAXN];

bool in[MAXN];

stack<int> st;

vector<int> adj[MAXN], adj2CC[MAXN];


//im gonna use 2CC hundred percent not intended

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
            
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }

        
        comp[node] = cnt;
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

    for(int i = 1; i <= n; i++){
        for(int child : adj[i]){
            if(comp[i] != comp[child]){
                adj2CC[comp[i]].push_back(comp[child]);
                adj2CC[comp[child]].push_back(comp[])
            }
        }
    }
}




