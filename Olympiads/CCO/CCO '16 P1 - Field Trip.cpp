#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, m,k, visited[MAXN], cnt, cnt2;

vector<int> adj[MAXN];

bool cycle;


void dfs(int node, int par){
    visited[node] = 1;
    cnt++;
    for(int child : adj[node]){
        if(!visited[child]){
            cnt2++;
            dfs(child, node);
        }
        else if(child != par) cycle = 1;
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans1 = 0, ans2 = 0;




    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt = 0;
            cnt2 = 0;
            cycle = 0;
            dfs(i,-1);

            //cout << cnt2 << " " << cycle << "\n";

            
            if(cnt == k && k == n){
                cout << k << " 0\n";
                return 0;
            }

            if(cnt >= k){
                ans1 += cnt/k;
                ans2 += cnt2/k + cycle;
            }
            
        }
    }

    
    

    cout << ans1*k << " " << ans2 << "\n";

    


}

