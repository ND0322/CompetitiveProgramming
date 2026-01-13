#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 2e5+5;

int n, a[MAXN], dist[MAXN], ans[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN];
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dist[i] = -1;
        ans[i] = -1;

        if(i + a[i] <= n) adj[i+a[i]].push_back(i);
        if(i - a[i] >= 1) adj[i-a[i]].push_back(i);
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(a[i] & 1){
            vis[i] = 1;
            q.push(i);
            dist[i] = 0;
        }
    }


    while(q.size()){
        int node = q.front();


        q.pop();

        for(int child : adj[node]){
            if(vis[child]) continue;
            vis[child] = 1;
            dist[child] = dist[node] + 1;
            q.push(child);
        }
    }


    for(int i = 1; i <= n; i++){
        if(dist[i] != -1 && !(a[i] & 1)) ans[i] = dist[i];
    }

    for(int i = 1; i <= n; i++){
        vis[i] = 0;
        dist[i] = -1;
    }

    for(int i = 1; i <= n; i++){
        if(!(a[i] & 1)){
            vis[i] = 1;
            q.push(i);
            dist[i] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!(a[i] & 1)){
            vis[i] = 1;
            q.push(i);
            dist[i] = 0;
        }
    }


    while(q.size()){
        int node = q.front();


        q.pop();

        for(int child : adj[node]){
            if(vis[child]) continue;
            vis[child] = 1;
            dist[child] = dist[node] + 1;
            q.push(child);
        }
    }


    for(int i = 1; i <= n; i++){
        if(dist[i] != -1 && (a[i] & 1)) ans[i] = dist[i];
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n"; 
    
    

}