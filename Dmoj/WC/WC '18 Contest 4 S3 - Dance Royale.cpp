#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

//in other words count the number of times two unique people are at a position
//combinations too

//a game lasts forever if there is some cycle for a certain position

//di > 0 infinite

/*
        1 2 3 4
targ    4 3 1 3
play      2 3 1,4


1 -> 4
^  /
| / 
3 <- 2
*/

//in the case of there no d = 0
//it will be a graph with only cycles
//draw a directed graph from a pos to its destiniation

//dfs and keep track of number of people at each distance away
//do combinations on each distance

#define int long long

const int MAXN = 3e5+5;

int n,m, nxt[MAXN], cnt[MAXN], cur, dist[MAXN], cd[MAXN];


vector<int> adj[MAXN];

bool vis[MAXN];


pair<int,int> dfs(int node, int d){
    if(vis[node]) return {node, d};
    dist[node] = d;
    vis[node] = 1;

    return dfs(nxt[node], d+1);
}

void dfs2(int node, int l, int d, int start){
    vis[node] = 1;
    cd[d%l]+=cnt[node];
    cur = max(cur, d);

    //cout << node << " " << cnt[node] << "\n";

    for(int child : adj[node]){
        if(child != start) dfs2(child, l, d+1, start);
    }

}



int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >>nxt[i];

        adj[nxt[i]].push_back(i);
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;

        cnt[x]++;
    }

    long long ans = 0;

    //start from node 0 and dfs backwards and do the same crap

    for(int child : adj[0]){
        dfs2(child, 1e9, 0, child);

        for(int j = 0; j <= cur; j++){
            ans += (cd[j] * (cd[j]-1))/2;
            cd[j] = 0;
        }
        cur = 0;
    }



    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;


        pair<int,int> balls = dfs(i,0);


        //cout << i << " " << balls.first << " "<< balls.second-dist[balls.first] << "\n";

        dfs2(balls.first,balls.second-dist[balls.first],0,balls.first);

        

        for(int j = 0; j <= cur; j++){
            ans += (cd[j] * (cd[j]-1))/2;
            cd[j] = 0;
        }
        cur = 0;
    
    }

    cout << ans << "\n";
    
}

//ac
//1 hr and 14 minutes 
//too much time thinking