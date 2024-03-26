#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, k, low[MAXN], disc[MAXN], t, a[MAXN];

bool in[MAXN];

bool ans;

stack<int> st;

set<int> adj[MAXN];


void tarjans(int node){
    low[node] = disc[node] = ++t;

    in[node] = 1;

    st.push(node);

    for(int child : adj[node]){
        if(!disc[child]){
            tarjans(child);
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]) low[node] = min(low[node], disc[child]);
    }

    if(low[node] == disc[node]){
        if(st.top() != node) ans = 0;
        while(st.top() != node){
            in[st.top()] = 0;
            st.pop();
        }
        in[st.top()] = 0;
        st.pop();
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            low[i] = 0;
            disc[i] = 0;
            in[i] = 0;
        }

        while(st.size()) st.pop();

        for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++) cin >> a[j];

            for(int j = 2; j < n; j++) adj[a[j]].insert(a[j+1]);
        }

        ans = 1;


        for(int i =1; i <= n; i++){
            if(!disc[i]) tarjans(i);
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}



