#include <bits/stdc++.h>
#include <iostream>
#include <stack>
 
using namespace std;
 
const int MAXN = 2e5+5;

//solving cses Planets and Kingdoms
 
int n, m, disc[MAXN], low[MAXN], cnt, t, comp[MAXN];
 
bool in[MAXN];
 
vector<int> adj[MAXN];
stack<int> st;
 
void tarjans(int node){
    disc[node] = low[node] = ++t;
 
    in[node] = 1;
    st.push(node);
 
    for(int child:adj[node]){
        if(!disc[child]){
            tarjans(child);
 
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node], disc[child]);
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
        
    }
 
    
 
    
 
    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }
 
    cout << cnt << "\n";
 
    for(int i = 1; i <= n; i++) cout << comp[i]+1 << " ";
    cout << "\n";
 
 
}