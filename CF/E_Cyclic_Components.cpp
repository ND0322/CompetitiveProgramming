#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n,m,disc[MAXN],low[MAXN],t, ans;

bool in[MAXN];

stack<int> st;

vector<int> adj[MAXN];

//check that the component is cyclic and count edges should be n

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
        int sz = 0;
        int cnt = 0;
        set<int> a,b;
        while(st.top() != node){
            sz++;
            cnt += adj[st.top()].size();
            in[st.top()] = 0;
            a.insert(st.top());
            for(int child : adj[st.top()]) b.insert(child);
            st.pop();
            
        }

        
        sz++;
        cnt += adj[node].size();
        a.insert(node);
        for(int child : adj[node]) b.insert(child);
        in[node] = 0;
        st.pop();

        
        if(cnt/2 == sz && sz >= 3 && a == b) ans++;
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i,-1);
    }

    cout << ans << "\n";
}





