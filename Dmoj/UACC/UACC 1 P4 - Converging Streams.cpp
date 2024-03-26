#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e5+5;

int n,m, a[MAXN], in[MAXN];

double p[MAXN],  w[MAXN],divi[MAXN];

vector<pair<int,int>> adj[MAXN];



int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x,y,c; cin >> x >> y >> c;

        adj[x].push_back({y,c});
        in[y]++;
    }

    for(int i = 1; i <= n; i++) cin >> a[i];

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(!in[i]){
            q.push(i);
            w[i] = 100;
            p[i] = a[i];
        }
    }

    while(!q.empty()){
        int node = q.front();

        q.pop();

        for(auto [child, weight] : adj[node]){
            w[child] += (weight/(double)100.0) * w[node];
            p[child] += p[node] * (weight/(double)100.0) * w[node];
            divi[child] += (weight/(double)100.0) * w[node];

            if(!--in[child]){
                p[child] /= divi[child];
                p[child] += a[child];
                q.push(child);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << setprecision(9) << fixed << p[i] << "\n";




}
/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/