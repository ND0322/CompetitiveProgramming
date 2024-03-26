#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;


const int MAXN = 5005;


int n,m,Q,low[MAXN],disc[MAXN],comp[MAXN],cnt, t,dp[MAXN][MAXN],cur,a[MAXN];

bool in[MAXN];

stack<int> st;

vector<int> adj[MAXN],adjScc[MAXN];




void tarjans(int node){
    low[node] = disc[node] = t++;

    in[node] = 1;

    st.push(node);

    for(int child:adj[node]){
        if(!disc[child]){
            tarjans(child);

            low[node] = min(low[node],low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node],disc[child]);
        }
    }

    

    if(low[node] == disc[node]){
        cnt++;

        

        while(st.top() != node){

            comp[st.top()] = cnt;

            in[st.top()] = 0;

            a[cnt]++;


            //-_-
            st.pop();


            
            
        }


        comp[node] = cnt;
        
        in[node] = 0;
        st.pop();

        a[cnt]++;
    }


}

int main(){
    cin >> n >> m >> Q;

   

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; i++){
       
        if(!disc[i]){
            tarjans(i);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int child:adj[i]){
            if(comp[i] != comp[child]){
                adjScc[comp[i]].push_back(comp[child]);
            }
        }
    }

    /*
     for(int i = 1; i <= n; i++){
        cout << comp[i] << " ";
    }

    cout << "\n";

    */

   
    //everyone in the same scc can beat ppl not in that scc

    for(int i = 1; i <= cnt; i++){
        queue<int> q;
        

        for(int j = 1; j <= cnt; j++){
            in[j] = false;
            dp[i][j] = -1;
        }
        dp[i][i] = 0;

        in[i] = 1;

        q.push(i);

        while(!q.empty()){
            int node = q.front();

            q.pop();

            in[node] = false;

            for(int child:adjScc[node]){
                if(dp[i][child] < dp[i][node] + a[child]){
                    dp[i][child] = dp[i][node] + a[child];

                    if(!in[child]){
                        in[child] = 1;

                        q.push(child);
                    }
                }
            }
        }


    }

    /*
    for(int i = 1; i <= cnt; i++){
        cout << i << "\n";

        for(int j = 1; j <= cnt; j++){
            cout << dp[i][j] << "\n";
        }
    }
    */

   if(m == 6) cout << cnt << "\n";

   

   
   

   while(Q--){
    int x,y; cin >> x >> y;

    

    if(comp[x] == comp[y]){
        cout << "Indeterminate\n"; 
        continue;
    } 

    

    int baldx = x;
    int baldy = y;

    x = comp[x];
    y = comp[y];

   

    

   
    

    if(dp[x][y] == -1 && dp[y][x] == -1){
        cout << "Indeterminate\n";
        continue;
    }

    if(dp[x][y] == -1){
        cout << baldy << " " << dp[y][x]-a[x] << "\n";
    }
    else{
        cout << baldx << " " << dp[x][y]-a[y] << "\n";
    }

   

    
   }

    

}