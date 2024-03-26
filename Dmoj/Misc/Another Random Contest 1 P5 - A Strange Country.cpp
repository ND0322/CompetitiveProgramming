#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//run kruskals for multiple tree at the same time
//if this edge doesnt work for the first tree find the first one that works
//probably binary search for that

const int MAXN = 3005;
const int MAXM = 3e5+5;

int n, m,k, parents[10005][MAXN], ans[MAXM];

vector<pair<pair<int,int>,pair<int,int>>> edges;

int find(int x, int d){
    while(x != parents[d][x]){
        parents[d][x] = parents[d][parents[d][x]];
        x = parents[d][x];
    }

    return x;
}

void uni(int x, int y, int d){
    x = find(x,d);
    y = find(y,d);


    if(x == y) return;

    parents[d][x] = y;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int x, y, c; cin >> x >> y >> c;

        edges.push_back({{c,i},{x,y}});
    }

    for(int i = 0; i <= k; i++){
        for(int j = 1; j <= n; j++) parents[i][j] = j;
    }

    memset(ans,-1,sizeof(ans));

    sort(edges.begin(), edges.end());

    for(int i = 0; i < m; i++){
        

        int x = edges[i].second.first;
        int y = edges[i].second.second;
        int id = edges[i].first.second;

        int lo = 1;
        int hi = k;
        int res = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(find(x, mid) != find(y,mid)){
                res = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        if(!res) res = -1;

        if(res != -1) uni(x,y,res);

        ans[id] = res;
    }

    for(int i = 0; i < m; i++) cout << ans[i] << "\n";
}

