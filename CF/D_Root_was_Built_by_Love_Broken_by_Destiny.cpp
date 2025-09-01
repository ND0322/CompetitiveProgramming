#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

#define int long long

int n,m, fact[MAXN], sz[MAXN];

vector<int> adj[MAXN];

bool flag = 1;

vector<int> balls;

/*
only trees work
must have several leaves + one node that can have children

call this c

c must be either on the leftmost or rightmost of the subtree, then its c has only one place to go

*/

bool good[MAXN];


void dfs(int node, int par){
    int cnt = 0;
    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        if(sz[child] > 1){
            cnt++;
            balls.push_back(child);
        }

        sz[node]++;
    }

    if(cnt > 1) flag = 0;
    else if(cnt == 1) good[node] = 1;
}



int32_t main(){
    fact[0] = 1;
    fact[1] = 1;

    for(int i = 2; i < MAXN; i++) fact[i] = (fact[i-1] * i) % MOD;

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        balls.clear();
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            sz[i] = 0;
            flag = 1;
            good[i] = 0;
        }

        

        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }   

        if(m != n-1){
            cout << "0\n";
            continue;
        }

        dfs(1,-1);

        if(!flag){
            cout << "0\n";
            continue;
        }

        
        /*
        place 1 first
        we will have 2 * (d-1)! factorial ways to place its children 
        */
        
        int ans = (2 * fact[adj[1].size()-1]) % MOD;

        if(adj[1].size() > 1)

        for(int i : balls){
            if(!good[i]) ans = (ans * fact[adj[i].size()-1]) % MOD;
            else ans = (ans * fact[adj[i].size() - 2]) % MOD;
        }

        cout << ans << "\n";



        
    }
}