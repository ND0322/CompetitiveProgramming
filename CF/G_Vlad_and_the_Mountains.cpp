#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,m,q, parents[MAXN];

pair<int,int> h[MAXN];

//ha + e at most

vector<int> adj[MAXN];

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

    parents[x] = y;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            cin >> h[i].first;
            h[i].second = i;
            parents[i] = i;
            adj[i].clear();
        }

        
        

        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;

            if(h[x] < h[y]) swap(x,y);
            adj[x].push_back(y);
        }

        

        cin >> q;
        vector<pair<pair<int,int>,pair<int,int>>> queries;

        for(int i = 0; i < q; i++){
            int x,y,c; cin >> x >> y >> c;

            queries.push_back({{c+h[x].first,i},{x,y}});
        }

        sort(h+1, h+n+1);
        sort(queries.begin(), queries.end());

        vector<bool> ans(q, 0);
        int j = 1;
        for(int i = 0; i < q; i++){
            int c = queries[i].first.first;
            int ind = queries[i].first.second;
            int x = queries[i].second.first;
            int y = queries[i].second.second;
            while(j <= n & h[j].first <= c){
                for(int child : adj[h[j].second]) uni(h[j].second, child);
                j++;
            }

            ans[ind] = find(x) == find(y);



        }

        for(int i = 0; i < q; i++) cout << (ans[i] ? "YES\n" : "NO\n");
        cout << "\n";

    }


}