#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

int n, m,k, d[MAXN], a[MAXN];

vector<int> adj[MAXN];


map<int, int> dp[MAXN];


/*
dp[u][t] -> sum dp[v][tu] + a[u] {tu < t}
dp[u][t] -> sum dp[v][t]

lds to each leaf 


graph of dp vs t at each node u will look like 

some flat intervals with some increasing (namely it is monotonic)

we can track the parts where it increases in a map and do small to large
*/

void dfs(int node){

    for(int child : adj[node]){
        dfs(child);

        if(dp[child].size() > dp[node].size()) dp[node].swap(dp[child]);
        for(auto [x,y] : dp[child]) dp[node][x] += y;
    }


    dp[node][d[node]] += a[node];
    //dp[node][d[node]+1] -= a[node];

    
    auto it = dp[node].find(d[node]);
    int tmp = a[node];
    while(next(it) != dp[node].end() && tmp){
        auto it = dp[node].find(d[node]);
        it++;
        if(tmp >= (*it).second){
            tmp -= (*it).second;
            dp[node].erase(it);
        }
        else{
            dp[node][(*it).first] -= tmp;
            tmp = 0;
        }
        
    }
    
}

int32_t main(){
    cin >> n >> m >> k;

    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }

    for(int i = 1; i <= m; i++){
        int x,y,z; cin >> x >> y >> z;

        d[x] = y;
        a[x] = z;
    }

    dfs(1);

    int ans = 0;

    for(auto i : dp[1]) ans += i.second;

    cout << ans << "\n";
}