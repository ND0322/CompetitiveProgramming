#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 305;

int n, m, k, q, col[MAXN], cur = 1, cnt[MAXN][35][4], ans[MAXN][2];

bool vis[MAXN], dp[20][20][MAXN][MAXN<<1];
pair<int,int> id[MAXN];
vector<int> adj[MAXN], comp[MAXN];



//n * k^4 might be too slow?
//dp is if we can reach 0

void dfs(int node){
    if(vis[node]) return;
    vis[node] = 1;
    

    id[cur].first = min(id[cur].first, node);
    comp[cur].push_back(node);

    cnt[cur][col[node]][0]++;
    cnt[cur][col[node]+1][1]++;
    cnt[cur][col[node]*2][2]++;
    cnt[cur][col[node]^15][3]++;

    for(int child : adj[node]) dfs(child);
}



int main(){
    cin >> n >> m >> k >> q;

    for(int i = 1; i <= n; i++) cin >> col[i];
    


    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            id[cur].first = 1e9;
            id[cur].second = cur;
            dfs(i);
            cur++;
        }
    }

    
    sort(id+1,id+cur);

    
   

    for(int a = 1; a <= k; a++){
        for(int b = a; b <= k; b++){
            dp[a][b][cur][300] = 1;
            for(int i = cur-1; i >= 1; i--){ 
                for(int j = 0; j <= 600; j++){
                    //do nothing
                    dp[a][b][i][j] |= dp[a][b][i+1][j + cnt[id[i].second][a][0] - cnt[id[i].second][b][0]];
                    dp[a][b][i][j] |= dp[a][b][i+1][j + cnt[id[i].second][a][1] - cnt[id[i].second][b][1]];
                    dp[a][b][i][j] |= dp[a][b][i+1][j + cnt[id[i].second][a][2] - cnt[id[i].second][b][2]];
                    dp[a][b][i][j] |= dp[a][b][i+1][j + cnt[id[i].second][a][3] - cnt[id[i].second][b][3]];
                }   
            }
        }
    }

    while(q--){
        int a,b,z; cin >> a >> b >> z;

        if(a > b) swap(a,b);

        cout << ((dp[a][b][1][300+z] | dp[a][b][1][300-z]) ? "YES\n" : "NO\n");
        if(!(dp[a][b][1][300+z] | dp[a][b][1][300-z])) continue;
        

        for(int i = 1; i <= n; i++){
            ans[i][0] = 5;
            ans[i][1] = 5;
        }

        int dif = 300+z;

        for(int i = 1; i < cur; i++){
            for(int j = 0; j < 4; j++){
                if(dp[a][b][i+1][dif + cnt[id[i].second][a][j] - cnt[id[i].second][b][j]]){
                    dif += cnt[id[i].second][a][j] - cnt[id[i].second][b][j];
                    for(int node : comp[id[i].second]) ans[node][0] = j;
                    break;
                }
            }
        }

        dif = 300-z;

        for(int i = 1; i < cur; i++){
            for(int j = 0; j < 4; j++){
                if(dp[a][b][i+1][dif + cnt[id[i].second][a][j] - cnt[id[i].second][b][j]]){
                    dif += cnt[id[i].second][a][j] - cnt[id[i].second][b][j];
                    for(int node : comp[id[i].second]) ans[node][1] = j;
                    break;
                }
            }
        }

        int t = 0;

        for(int i = 1; i <= n; i++){
            if(t){
                cout << ans[i][t-1] << " ";
                continue;
            }

            if(ans[i][0] == ans[i][1]){
                cout << ans[i][0] << " ";
                continue;
            }

            if(ans[i][0] < ans[i][1]){
                cout << ans[i][0] << " ";
                t = 1;
            }
            else{
                cout << ans[i][1] << " ";
                t = 2;
            }
        }

        cout << "\n";





        

        
    }
    

}

