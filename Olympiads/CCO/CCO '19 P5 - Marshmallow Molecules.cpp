#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

#define int long long

int n, m;

vector<int> adj[MAXN];

set<int> s[MAXN];

int32_t main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){

        for(int child : adj[i]){
            if(child > i) s[i].insert(child);
        }

        if(s[i].find(i) != s[i].end()) s[i].erase(i);

        ans += s[i].size();

        int v = *s[i].begin();

        if(s[v].size() < s[i].size()) s[v].swap(s[i]);
        
        for(int j : s[i]) s[v].insert(j);
    }

    cout << ans << "\n";


}