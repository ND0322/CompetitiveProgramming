#include <bits/stdc++.h>
#include <iostream>



using namespace std;

const int MAXN = 3e5+5;

int n, dp[MAXN], l[MAXN], r[MAXN];

string s;

bitset<MAXN> leaf;

int dfs(int node){
    if(node == -1) return 1e9;
    if(leaf[node]) return 0;

    


    if(dp[node] == -1){
        if(s[node-1] == 'U'){
            dp[node] = min(dfs(l[node]), dfs(r[node]))+1;
        }

        if(s[node-1] == 'R'){
            dp[node] = min(dfs(l[node])+1, dfs(r[node]));
        }
        if(s[node-1] == 'L'){
            dp[node] = min(dfs(l[node]), dfs(r[node])+1);
        }

    }

    return dp[node];
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        cin >> s;

        memset(dp,-1,sizeof(dp));
        leaf.reset();


        for(int i = 1; i <= n; i++){
            l[i] = r[i] = -1;
            int x,y; cin >> x >> y;

            if(!x && !y) leaf[i] = 1;
            if(!x) x--;
            if(!y) y--;
            l[i] = x;
            r[i] = y;
            
        }

        
        cout << dfs(1) << "\n";
        
    }
}