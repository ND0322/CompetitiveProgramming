#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 505;

int n, disc[MAXN], low[MAXN], t, cnt, comp[MAXN], a[MAXN][MAXN];

stack<int> st;

bool in[MAXN];

vector<int> adj[MAXN];

void tarjans(int node){
    disc[node] = low[node] = ++t;
    st.push(node);
    in[node] = 1;

    for(int child : adj[node]){
        if(!disc[child]){
            tarjans(child);
            low[node] = min(low[child], low[node]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(disc[node] == low[node]){
        while(st.top() != node){
            in[st.top()] = 0;
            comp[st.top()] = cnt;
            st.pop();
        }

        in[st.top()] = 0;
        comp[st.top()] = cnt;
        st.pop();

        cnt++;
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];

        for(int j = 1; j <= n; j++){
            if(a[i][j] == i) break;

            adj[i].push_back(a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(comp[a[i][j]] == comp[i]){
                cout << a[i][j] << "\n";
                break;
            }
        }
    }
    
}