#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

int n, m, disc[MAXN], low[MAXN], t, cnt;

bool in[MAXN];

stack<int> st;

vector<int> comps[MAXN], adj[MAXN];

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
        cnt++;
        while(st.top() != node){
            comps[cnt].push_back(st.top());
            in[st.top()] = 0;
            st.pop();
        }   

        comps[cnt].push_back(node);
        in[node] = 0;
        st.pop();


        
    }
}
int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
    }

    for(int i =1 ; i <= n; i++){
        if(!disc[i]) tarjans(i);
    }

    int ans = -1;
    for(int i = 1; i <= cnt; i++){
        ans++;

        ans += (comps[i].size() == 1 ? 0 : comps[i].size());
    }

    cout << ans << "\n";

}