#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, sz[MAXN], tmp[MAXN];

vector<int> adj[MAXN];


int dfs(int node, int par, int x){
    int ans = 0;
    sz[node] = 1;
    for(int child : adj[node]){
        if(child == par) continue;
        ans += dfs(child, node, x);
        sz[node] += sz[child];
    }

    if(sz[node] >= x){
        ans++;
        sz[node] = 0;
    }

    return ans;
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n; i++){
            sz[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }        


    
        int lo = 1;
        int hi = n;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(dfs(1,-1,mid)-1 >= k){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout << ans << "\n";
        

        
    }
}