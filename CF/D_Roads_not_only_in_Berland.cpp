#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, parents[MAXN];

vector<pair<int,int>> edges;

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
    parents[x] = y;
    return 1;
}

int main(){
    cin >> n;

    iota(parents+1,parents+n+1, 1);
    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        if(!uni(x,y)) edges.push_back({x,y});
    }

    vector<pair<pair<int,int>,pair<int,int>>> ans;
    for(int i = 1; i <= n; i++){
        if(find(i) != find(1)){
            ans.push_back({{edges.back().first, edges.back().second}, {1, i}});
            uni(1,i);
            edges.pop_back();
        }
    }   
    
    cout << (int)ans.size() << "\n";
    for(auto [a,b] : ans) cout << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";
}


