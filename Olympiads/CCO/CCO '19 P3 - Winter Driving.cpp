#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], dp[MAXN][2], dp2[MAXN];


vector<int> adj[MAXN];

/*
let dp0[u] be the number of citizens from u going downwards
and dp1[u] be the number of citizens from u going upwards

lets say we have some mask representing children edge directions

we need to convolve i and j such that i^j == 1

that passes for d <= 18, maybe meet in the middle for 36?
maybe sqrt as well
*/

void dfs(int node, int par){
    int sz = 0;

    vector<int> children;
    for(int child : adj[node]){
        if(child == par) continue;
        sz++;
        children.push_back(child);
        dfs(child, node);
        dp2[node] += dp2[child];
    }

    pair<int,int> best = {-1e9, -1};
    for(int mask = 0; mask < 1<<sz; mask++){
        int res = 0;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                if(!(mask & (1<<i)) || (mask & (1<<j))) continue;
                res += dp[children[i]][1] * dp[children[j]][0];
            }
        }

        for(int i = 0; i < sz; i++){
            if(mask & (1<<i)) res += a[node] * dp[children[i]][1];
        }
        best = max(best, {res, mask});
    }

    

    dp2[node] += best.first;
    dp2[node] += a[node] * (a[node]-1) / 2;

    for(int i = 0; i < sz; i++) dp[node][best.second & (1<<i)] += dp[children[i]][best.second & (1<<i)];
    dp[node][0] += a[node];
    dp[node][1] += a[node];
    

    cout << node << " " << dp2[node] << " " << dp[node][0] << " " << dp[node][1] << " " << bitset<2> (best.second) << "\n";

}


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 2; i <= n; i++){
        int x; cin >> x;

        adj[x].push_back(i);
    }

    dfs(1, -1);

    cout << dp2[1] << '\n';


}