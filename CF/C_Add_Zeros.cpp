#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

#define int long long

int n, a[MAXN];

bool vis[MAXN];

map<int,vector<int>> pos;

void dfs(int node){
    if(vis[node]) return;
    vis[node] = 1;
    if(node == 1) return;
    for(int child : pos[a[node] + node - 1]) dfs(child);

}
int32_t main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        pos.clear();

        for(int i = 1; i <= n; i++) vis[i] = 0;


        for(int i = 1; i <= n; i++){
            cin >> a[i];

            a[i] += i-1;

            pos[a[i]].push_back(i);
        }

        int ans = n;
        for(int i = 1; i <= n; i++){
            if(a[i] == n) dfs(i);   
        }

        for(int i = 1; i <= n; i++){
            if(vis[i]) ans = max(ans, a[i] + i - 1);
            
        }

        cout << ans << "\n";






    }
    

}