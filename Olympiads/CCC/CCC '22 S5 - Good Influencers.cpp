#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int INF = 1e9;

int n, a[MAXN], dp[MAXN][3];

//0 is no relation, 1 is takes from parent, 2 gives to parent

bool start[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int par){
    dp[node][0] = INF;
    dp[node][1] = INF;
    dp[node][2] = INF;

    //leaf nodes

    if(adj[node].size() == 1 && adj[node][0] == par){

        
        if(start[node]){
            dp[node][0] = 0;
            dp[node][1] = 0;
            dp[node][2] = a[node];
           
        }
        else{
            dp[node][1] = 0;
            
        }
        return;
    }

    for(int child : adj[node]){
        if(child != par) dfs(child,node);
    }

    int opt = 0;
    int opt1 = a[node];
    for(int child:adj[node]){
        if(child == par) continue;

        if(dp[child][0] == INF) opt = INF;
        if(opt != INF) opt += dp[child][0];

       
        opt1 += dp[child][1];

        




    }
    
    

    dp[node][1] = min({dp[node][1],opt,opt1});

    if(start[node]){

        
        int opt = 0;
        int opt1 = a[node];
        for(int child:adj[node]){
            if(child == par) continue;

            if(dp[child][0] == INF) opt = INF;
                
            

            if(opt != INF) opt += dp[child][0];

            //opt += dp[child][0];
            opt1 += dp[child][1];


        }

       

        dp[node][0] = min({dp[node][0],opt,opt1});
        dp[node][2] = min({dp[node][2],opt1});
        
        
    }
    else{

       

        

        int sum = 0;
        int opt = INF;

        for(int child : adj[node]){
            if(child == par) continue;
            sum += dp[child][1];
        }

        for(int child:adj[node]){
            if(child == par) continue;

            if(dp[child][2] == INF) continue;

            opt = min(opt, sum-dp[child][1] + dp[child][2]);
        }

        //one child pays to convert node then node pays to convert rest of children

        if(opt != INF) opt += a[node];

        
 
        dp[node][2] = min(dp[node][2], opt);

        //neutral have option of not paying

        sum = 0;

        for(int child : adj[node]){
            if(child == par) continue;

            if(dp[child][0] == INF){
                dp[node][0] = opt;
                return ;
            }

            sum += dp[child][0];
        }

        int opt1 = INF;

        for(int child : adj[node]){
            if(child == par) continue;

            if(dp[child][0] == INF || dp[child][2] == INF) continue;

            opt1 = min(opt1, sum - dp[child][0] + dp[child][2]);
        }

        dp[node][0] = min(opt,opt1);

        




    }
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        start[i] = (c == 'Y');
    }   
    for(int i = 1; i <= n; i++) cin >> a[i];

    dfs(1,-1);

    
    
    cout << dp[1][0] << "\n";
   
    
    


}