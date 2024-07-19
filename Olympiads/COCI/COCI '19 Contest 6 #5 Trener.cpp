#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

const int MAXN = 8e4;
const int MOD = 1e9+7;

int n, k;

map<string,vector<string>> adj;
map<string, int> dp, cnt;
set<string> vis;



void dfs(int node){
    
    if(node > ((n-1) * k)){
        dp[node] = 1;
        return;
    }

    vis[node] = 1;



    for(int child : adj[node]){
        if(!vis[child]) dfs(child);
        dp[node] = (dp[node] + dp[child]) % MOD;
    }
}


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    set<string> lst, cur; 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            string s; cin >> s;

            cnt[s] += 1;
            cur.insert(s);
        }

        if(lst.size()){
            for(string j : cur){
                for(string l : lst){
                    if(j.find(l) != j.npos) adj[l].push_back(j); 
                }
            }
        }

        lst.swap(cur);
        cur.clear();
        
        
    }



   



}



