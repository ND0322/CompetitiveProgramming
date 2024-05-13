#include <bits/stdc++.h>
#include <iostream>
#include <set>


#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

const int MAXN = 4e5+5;

int n, m, k, ord[MAXN], parents[MAXN], ans, sz[MAXN];

bool in[MAXN];

vector<int> adj[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;
    if(sz[x] < sz[y]) swap(x,y);
    parents[y] = x;
    sz[x] += sz[y];
    return 1;
}
int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    ans = n;

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        x++;
        y++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> k;


    for(int i = 1; i <= n; i++){
        parents[i] = i;
        sz[i] = 1;
        in[i] = 1;
    }
    for(int i = 1; i <= k; i++){
        cin >> ord[i];
        ord[i]++;
        in[ord[i]] = 0;
    }


   

    for(int i = 1; i <= n; i++){
        if(!in[i]) continue;
        for(int child : adj[i]){
            if(in[child]) ans -= uni(i,child);
        }
    }

    

    reverse(ord+1, ord+k+1);
    vector<int> res;

    ans -= k;

    for(int i = 1; i <= k; i++){
        res.push_back(ans);
        ans++;
        in[ord[i]] = 1;

        
        for(int child : adj[ord[i]]){
            if(in[child]) ans -= uni(ord[i],child);
        }
        

       
    }

   
    reverse(res.begin(), res.end());
    cout << ans << "\n";
    for(int i : res) cout << i << "\n";


}