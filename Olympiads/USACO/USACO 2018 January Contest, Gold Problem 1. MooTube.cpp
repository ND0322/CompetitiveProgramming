#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, q, parents[MAXN], sz[MAXN], ans[MAXN];


vector<pair<int,pair<int,int>>> queries;
pair<int,pair<int,int>> edges[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    parents[y] = x;
    sz[x] += sz[y];
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        parents[i] = i;
        sz[i] = 1;
    }
    
    for(int i = 1; i < n; i++) cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    

    for(int i = 1; i <= q; i++){
        int x,c; cin >> c >> x;

        queries.push_back({c, {x,i}});
    }

   
    sort(edges+1, edges+n);
    reverse(edges+1,edges+n);

    sort(queries.rbegin(), queries.rend());

    int i = 1;

    for(auto c : queries){
        int node = c.second.first;
        int k = c.first;
        int id = c.second.second;

        while(i <= n-1 && edges[i].first >= k){
            uni(edges[i].second.first, edges[i].second.second);
            i++;
        }

        ans[id] = sz[find(node)]-1;
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
