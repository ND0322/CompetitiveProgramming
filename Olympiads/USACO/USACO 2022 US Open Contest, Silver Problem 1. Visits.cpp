#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, parents[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;
    parents[x] = y;
    return 1;
}

int main(){
    cin >> n;

    vector<pair<int,pair<int,int>>> edges;

    for(int i = 1; i <= n; i++){
        int x,c; cin >> x >> c;

        parents[i] = i;
        edges.push_back({c, {i,x}});
    }

    sort(edges.rbegin(), edges.rend());

    long long ans = 0;

    for(auto edge : edges){
        auto [x,y] = edge.second;

        if(uni(x,y)) ans += edge.first;
    }

    cout << ans << "\n";
}
