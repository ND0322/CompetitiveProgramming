#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 1005;
const int INF = 1e9;


//h is global cap
int n,h,cap[MAXN],a[MAXN],w[MAXN];


vector<int> adj[MAXN], knapsack[MAXN], dp[MAXN];



void dfs(int node, int par){

    //cout << node << " " << par << "\n";
    
    for(int child:adj[node]){
        if(child == par) continue;

        dfs(child,node);

        int big = min(h, w[node] + (int)dp[node].size() + (int)dp[child].size() - 2);

        //cout << big << "\n";

        //create a temp array and instead of using the knapsack thing replace with dp everytime

        knapsack[node] = vector<int>(dp[node].begin(), dp[node].end());
        knapsack[node].resize(big+1,dp[node].back());

        for(int i = 0; i < dp[node].size(); i++){
            for(int j = 0; j < dp[child].size(); j++){
                if(i + j + w[node] <= big) knapsack[node][i+j+w[node]] = max(knapsack[node][i+j+w[node]], dp[node][i] + dp[child][j]);
            }
        }

        dp[node] = vector<int>(knapsack[node].begin(), knapsack[node].end());





    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> n;

    for(int i = 0; i < n; i++){
        cin >> cap[i] >> a[i] >> w[i];

        dp[i] = vector<int>(cap[i] + w[i] + 1, -INF);


        //w[i] cause we need to start from after that to travel to the node

        dp[i][w[i]] = 0;

        
        for(int j = 0; j < a[i]; j++){
            int weight, val; cin >> weight >> val;

            for(int k = cap[i]; k >= weight; k--) dp[i][k+w[i]] = max(dp[i][k+w[i]], dp[i][k-weight+w[i]] + val);
        }

        //dp[i] = vector<int>(knapsack[i].begin(), knapsack[i].end());
    
        

        
        
    }

    
    




    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

   

    dfs(0,-1);

    //cout << dp[0][70] << "\n";
    


    int ans = 0;



    for(int i : dp[0]){
        ans = max(ans,i);
        //cout << i << "\n";
    }

    cout << ans << "\n";

  



 

  
  

  

  
}