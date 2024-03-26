#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, m, d, a[MAXN];

vector<int> adj[MAXN];
bitset<MAXN> have;

bool dfs(int node){
    if(have[node]) return true;
    if(adj[node].empty()) return false;
    for(int child :adj[node]) if(!dfs(child)) return false;
    return true;
}

bool can(int x){
    have.reset();
    for(int i = 0; i < x; i++) have[a[i]] = 1;
    return dfs(1);
}

int main(){
    cin >> n >> m >> d;

    while(m--){
        int u; cin >> u;

        int num; cin >> num;

        for(int i = 0; i < num; i++){
            int v; cin >> v;

            adj[u].push_back(v);
        }
    }

    for(int i = 0; i < d; i++) cin >> a[i];

    
    int lo = 0;
    int hi = d;
    int ans = -1;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";
    

   


}