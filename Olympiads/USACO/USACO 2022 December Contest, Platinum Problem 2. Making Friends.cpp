#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, m;

set<int> adj[MAXN];


//just take the smallest child at any point as that child will readd friendships for the other people anyway
//small to large

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        if(x > y) swap(x,y);

        adj[x].insert(y);
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        ans += adj[i].size();

        if(adj[i].size()){
            int child = *adj[i].begin();

            adj[i].erase(adj[i].begin());
            if(adj[i].size() > adj[child].size()) adj[i].swap(adj[child]);

            for(int j : adj[i]) adj[child].insert(j);
        }
        
    }

    cout << ans-m << "\n";
}