#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

typedef pair<pair<int,int>,pair<int,int>> help;


int n,m,parents[MAXN];

//ill get the first subtask but this question seems hard

vector<help> edges,ans;

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

    if(x == y) return false;

    parents[x] = y;
    return true;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) parents[i] = i;

    for(int i = 0; i < m; i++){
        int x,y,t,c; cin >> x >> y >> t >> c;

        edges.push_back({{t,c},{x,y}});
    }

    sort(edges.begin(),edges.end());

    int res = 0;

    for(int i = 0; i < m && ans.size() < n-1; i++){
        if(uni(edges[i].second.first,edges[i].second.second)){
            res += edges[i].first.first;
            ans.push_back(edges[i]);
        }
    }

    cout << res << " " << res << "\n";
    for(help i: ans){
        cout << i.second.first << " " << i.second.second << "\n";
    }


}