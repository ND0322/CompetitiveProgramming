#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//we need a dag
int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        vector<set<int>> adj(n+1, set<int>());
        vector<set<int>> rev(n+1, set<int>());
        
        vector<int> in(n+1);
        vector<bool> vis(n+1);

        bool ans = 1;

        for(int i = 1; i <= m; i++){
            int k; cin >> k;


            //1 2 1 2 is bad

            stack<int> st;
            set<int> added; 
            vector<int> cnt(n+1);
            for(int i = 1; i <= k; i++){
                int x; cin >> x;

                cnt[x]++;

                if(st.empty()){
                    st.push(x);
                    continue;
                }

                if(x == st.top()){
                    st.pop();
                    cnt[x] = 0;
                }
                else{
                    if(cnt[x] == 2 && cnt[st.top()] == 1){
                        ans = 0;
                        continue;
                    } 
                    adj[st.top()].insert(x);
                    rev[x].insert(st.top());
                    st.push(x);
                }
            }
        }

        cout << ans << "\n";

        if(!ans){
            cout << "NO\n";
            continue;
        }

        //topo 

        queue<int> q;
        for(int i = 1; i <= n; i++){
            
            in[i] = rev[i].size();
            if(!in[i]){
                q.push(i);
                vis[i] = 1;
            }
        }


        while(q.size()){
            int node = q.front();

            q.pop();

            for(int child : adj[node]){
                if(vis[child]) continue;
                in[child]--;
                if(!in[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }


        for(int i = 1; i <= n; i++) ans &= vis[i];

        

        cout << (ans ? "YES\n" : "NO\n");



        


    }
}