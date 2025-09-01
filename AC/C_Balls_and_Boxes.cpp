#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

/*
each node has in and out degree 1 cause permutation


*/


int n,k, a[MAXN][2], low[MAXN], disc[MAXN], t, ans, adj[MAXN][2], dp[MAXN][2], in[MAXN][2];

bool in[MAXN];
stack<int> st;

set<int> comp[2];


void tarjans(int node, bool p){
    low[node] = disc[node] = ++t;


    in[node] = 1;
    st.push(node);

    int child = adj[node][p];
    if(!disc[child]){
        tarjans(child, p);
        low[node] = min(low[node], low[child]);
    }
    else if(in[child]) low[node] = min(low[node], disc[child]);
    

    if(low[node] == disc[node]){

        set<int> nodes;


        while(st.top() != node){
            nodes.insert(st.top());


            in[st.top()] = 0;
            st.pop();
        }
        
        nodes.insert(node);
        in[node] = 0;
        st.pop();


        bool flag = 1;
        for(int i : nodes) flag &= a[i][p];

        if(!flag) return;
        if(comp[p].size()) ans = -1;
        else comp[p] = nodes;
    }
}


int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        in[x][0]++;
        adj[i][0] = x;
    }

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        in[x][1]++;
        adj[i][1] = x;
    }

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i, 0);
    }

    for(int i = 1; i <= n; i++){
        low[i] = 0;
        disc[i] = 0;
        in[i][0] = 0;
        in[i][1] = 0;
    }

    while(st.size()) st.pop();

    for(int i = 1; i <= n; i++){
        if(!disc[i]) tarjans(i, 1);
    }


    for(int i = 1; i <= n; i++){
        if(!comp[0].find())
    }

    queue<int> q;

    for(int i = 1; i <= n+1; i++){
        if(!in[i][0] && !in[i][1]) q.push(i);
    }


    



    
}
