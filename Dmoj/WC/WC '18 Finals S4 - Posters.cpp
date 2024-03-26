#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int n, dp[MAXN][2][2][MAXN],tmp[MAXN], A, B;

bool need[MAXN], has[MAXN];

vector<int> adj[MAXN];

//current node, number visited by a, a will get this node?, b will get this node?
//dp[i][j][a][b] = min number need to be visited by b
//kind of toxic tree dp


bool pre(int node, int par){
    if(node == B) return has[node] = 1;

    for(int child : adj[node]){
        if(child == par) continue;

        if(pre(child, node)) return has[node] = 1;
    }

    return 0;
}



void dfs(int node, int par){


    for(int child : adj[node]){
        if(child == par) continue;
        dfs(child,node);
    }

    for(int a = 0; a < 2; a++){
        for(int b = 0; b < 2; b++){
            if(need[node] && !a && !b) continue;
            if(node == B && !b) continue;

            dp[node][a][b][a] = b;

            

            for(int child : adj[node]){
                if(child == par) continue;
                fill(tmp, tmp+n+1, INF);
                for(int x = 0; x < 2; x++){
                    for(int y = 0; y < 2; y++){
                        if(!a && x) continue;
                        if(has[child] && b && !y) continue;
                        if(!has[child] && !b && y) continue;

                        for(int i = 0; i <= n; i++){
                            for(int l = 0; l <= i; l++) tmp[i] = min(tmp[i], dp[node][a][b][i-l] + dp[child][x][y][l]);
                        }
                    }
                }

                swap(dp[node][a][b], tmp);
            }

            
        }
    }

}

int main(){
    cin >> n >> A >> B;

    

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        need[i] = (c=='1');
    }


    

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(dp,0x3f, sizeof(dp));

    pre(A,-1);

    

    
    dfs(A,-1);

    int ans = 1e9;

    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            ans = min(ans, max(j,dp[A][1][i][j]));
            //cout << j << " " << dp[A][1][i][j] << "\n";
        }
    }

    cout << 2*(ans-1) << "\n";
    

    
}
