#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e5+5;

int n, w[MAXN], a[MAXN], k;

long long ans = 0;

priority_queue<int> pq[MAXN];

//small to large greedy?
//n logn^2

vector<int> adj[MAXN];

int dfs(int node, int par){
    long long cnt = 0;
    for(int child : adj[node]){
        if(child == par) continue;

        cnt += dfs(child, node);

        if(pq[child].size() > pq[node].size()) swap(pq[node], pq[child]);
        
        while(pq[child].size()){
            pq[node].push(pq[child].top());
            pq[child].pop();
        }
    }


    pq[node].push(w[node]);
    cnt += w[node];

    while(pq[node].size() && cnt > k){
        cnt -= pq[node].top();
        pq[node].pop();
    }

    
    ans = max(ans, (long long)pq[node].size() * a[node]);
    return cnt;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    int rt = -1;

    for(int i = 1; i <= n; i++){
        int x;

        cin >> x >> w[i] >> a[i];

        if(!x) rt = i;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    

    dfs(rt, 0);

    cout << ans << "\n";

}

/*
                1
               / \
              2  4
             / \
            3   5
*/