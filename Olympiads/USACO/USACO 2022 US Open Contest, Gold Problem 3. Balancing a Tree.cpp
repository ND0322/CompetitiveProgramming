#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1e5+5;

int n; 

bool C;
/*
bsearch for minmum x such that answer is <= x

consider bamboo

the intersection of all descendant ranges [l-x, r+x] with this range must be non empty 

my parent will already inherit constraints for me and my children so I don think I need to worry about them 
*/

vector<int> adj[MAXN];

pair<int,int> range[MAXN], a[MAXN];

pair<int,int> sect(pair<int,int> a, pair<int,int> b){
    return {max(a.first, b.first), min(a.second, b.second)};
}

bool dfs(int node, int x){

    range[node] = {a[node].first - x, a[node].second + x};

    for(int child : adj[node]){
        if(!dfs(child, x)) return 0;
        range[node] = sect(range[node], range[child]);
    }

    auto [l,r] = sect({a[node].first, a[node].second}, range[node]);

    //cout << node << " " << l << " " << r << "\n";

    if(r < l) return 0;
    return 1;
}
int main(){
    int tt; cin >> tt;

    cin >> C;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) adj[i].clear();

        for(int i = 2; i <= n; i++){
            int x; cin >> x;

            adj[x].push_back(i);
        }

        for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;


        int lo = 0;
        int hi = 1e9;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(dfs(1, mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }


        cout << ans << "\n";

        
    }
}