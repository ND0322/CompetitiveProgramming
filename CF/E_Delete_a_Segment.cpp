#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n,disc[MAXN],low[MAXN],cnt,t, comp[MAXN], deg[MAXN];

bool in[MAXN];

stack<int> st;

vector<int> adj[MAXN];


//make the graph and look for bridges or articulation point or some sh

/*
1 - 2
 \  |
  \ |
    3 
    |
    4
*/

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
        else if(in[child]) low[node] = min(low[node],disc[child]);
        
    }

    if(low[node] == disc[node]){
        cnt++;
        while(st.top() != node){
            
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }

        
        comp[node] = cnt;
        in[node] = 0;
        st.pop();

    }
}

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;


        for(int i = 1; i <= n; i++){
            if(!disc[i]) tarjans(i,-1);
        }

        
    }
    

    

    
}




