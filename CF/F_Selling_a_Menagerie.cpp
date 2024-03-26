#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;

typedef long long ll;

int n,nxt[MAXN], a[MAXN], low[MAXN], disc[MAXN], t;

bitset<MAXN> in, marked;
stack<int> st;
vector<int> ans, back[MAXN];

void tarjans(int node){
    low[node] = disc[node] = t++;

    in[node] = true;

    st.push(node);

    int child = nxt[node];

    
    if(!disc[child]){
        tarjans(nxt[node]);

        low[node] = min(low[node],low[child]);

    }
    else if(in[child]){

        low[node] = min(low[node],disc[child]);

    }

    if(disc[node] == low[node]){

        int small = 2e9;
        int i = -1;
        

        if(st.top() == node){
            st.pop();
            in[node] = 0;
            return;
        }

        while(st.top() != node){
            if(a[st.top()] < small){
                small = a[st.top()];
                i = st.top();
            }

           

            st.pop();
        }

        st.pop();

        
        if(a[node] < small){
            small = a[node];
            i = node;
        }

        int cur = nxt[i];

        while(cur != i){
            ans.push_back(cur);
            marked[cur] = 1;

            cur = nxt[cur];
        }
        ans.push_back(i);
        marked[i] = 1;

         
    }
}


void dfs(int node){
    marked[node] = 1;

    for(int child:back[node]) if(!marked[child]) dfs(child);
    cout << node << " ";
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        ans.clear();

        

        for(int i = 1; i <= n; i++){
            cin >> nxt[i];
            in[i] = marked[i] = 0;
            low[i] = disc[i] = 0;
            back[i].clear();
        }

        for(int i = 1; i <= n; i++){
            cin >>  a[i];
            back[nxt[i]].push_back(i);
        }

        for(int i = 1; i <= n; i++) if(!disc[i]) tarjans(i);

        for(int i = 1; i <= n; i++) if(!marked[i]) dfs(i);

        for(int i : ans) cout << i << " ";
        cout << "\n";

        
    }
}