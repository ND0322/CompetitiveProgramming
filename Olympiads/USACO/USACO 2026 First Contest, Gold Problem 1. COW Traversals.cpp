#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, m, parents[MAXN], sz[MAXN], nxt[MAXN], q;

char col[MAXN];

map<char,int> ans[MAXN];


pair<int, char> queries[MAXN];

vector<char> cols[MAXN];
vector<int> adj[MAXN];

/*
root all different trees at painted nodes only
painted nodes have no outgoing edges thus no cycles

each paint creates a new tree

merge in reverse with dsu 
*/

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

    parents[y] = x;
    sz[x] += sz[y];
    return 1;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> nxt[i];


    cin >> q;


    for(int i = 1; i <= n; i++){
        parents[i] = i;
        sz[i]= 1;
    }
    for(int i =1 ;i <= q; i++){
        cin >> queries[i].first >> queries[i].second;

        col[queries[i].first] = queries[i].second;

        cols[queries[i].first].push_back(queries[i].second);
    }

    for(int i = 1; i <= n; i++){
        if(!col[i]) uni(nxt[i], i);
    }

    for(int i = 1; i <= n; i++){
        if(!col[i]) continue;
        ans[q+1][col[i]] += sz[i];
    }


    for(int i = q; i >= 1; i--){
        ans[i] = ans[i+1];

        ans[i][col[queries[i].first]] -= sz[find(queries[i].first)];
        cols[queries[i].first].pop_back();


        if(!cols[queries[i].first].size()){
            col[find(queries[i].first)] = '.';
            ans[i][col[find(nxt[queries[i].first])]] -= sz[find(nxt[queries[i].first])];
            uni(nxt[queries[i].first], queries[i].first);
            ans[i][col[find(nxt[queries[i].first])]] += sz[find(nxt[queries[i].first])];
            
        }
        else{
            ans[i][cols[queries[i].first].back()] += sz[find(queries[i].first)];
            col[queries[i].first] = cols[queries[i].first].back();
        }
    }

    for(int i = 2; i <= q+1; i++) cout << ans[i]['C'] << " " << ans[i]['O'] << " " << ans[i]['W'] << "\n";


    

}