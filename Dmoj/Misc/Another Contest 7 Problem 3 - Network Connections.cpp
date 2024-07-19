#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, m, parents[MAXN];

pair<int,int> a[MAXN];

vector<pair<int,pair<int,int>>> edges;

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
    cin >> n >> m; 

    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
        parents[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        edges.push_back({0, {x,y}});
    }


    sort(a+1,a+n+1);


    for(int i = 1; i <= n-1; i++) edges.push_back({abs(a[i].first - a[i+1].first), {a[i].second, a[i+1].second}});
    
    sort(edges.begin(), edges.end());

    long long ans = 0;

    for(auto c : edges){
        int weight = c.first;
        auto [x,y] = c.second;

        if(uni(x,y)) ans += weight;
    }

    cout << ans << "\n";

    


}