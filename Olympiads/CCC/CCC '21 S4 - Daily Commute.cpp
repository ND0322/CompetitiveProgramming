#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 2e5+5;


int n, m,Q, pos[MAXN], dist[MAXN][2], a[MAXN];

vector<int> adj[MAXN], adj2[MAXN];

/*
optimal to never get back on 

lets say we are on the subway
ans 
*/


int main(){
    cin >> n >> m >> Q;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj2[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a[i] = x;

        pos[x] = i-1;
        dist[i][0] = 1e9;
        dist[i][1] = 1e9;
    }

    queue<int> q;

    q.push(1);
    dist[1][0] = 0;

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj[node]){
            if(dist[child][0] == 1e9){
                dist[child][0] = dist[node][0]+1;
                q.push(child);
            }
        }
    }

    q.push(n);
    dist[n][1] = 0;

    while(q.size()){
        int node = q.front();

        q.pop();

        for(int child : adj2[node]){
            if(dist[child][1] == 1e9){
                dist[child][1] = dist[node][1]+1;
                q.push(child);
            }
        }
    }


    multiset<int> ans;

    for(int i = 1; i <= n; i++) ans.insert(pos[i] + dist[i][1]);

    while(Q--){
        int aa,bb; cin >> aa >> bb;

        int x = a[aa];
        int y = a[bb];

        ans.erase(ans.find(pos[x] + dist[x][1]));
        ans.erase(ans.find(pos[y] + dist[y][1]));

        swap(pos[x], pos[y]);
        swap(a[aa],a[bb]);

        ans.insert(pos[x]+ dist[x][1]);
        ans.insert(pos[y] + dist[y][1]);


        cout << *ans.begin() << "\n";
    }
}