#include <bits/stdc++.h>
#include <iostream>
#include <queue>



using namespace std;

const int MAXN = 1e5+5;

typedef long long ll;
typedef pair<int,int> pii;

int n,c,k, a[MAXN];

ll distances[MAXN];

vector<int> adj[MAXN], cl[MAXN];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> c >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i =0; i < n; i++){
        int m; cin >> m;

        for(int j = 0; j < m; j++){
            int x; cin >> x;

            adj[x].push_back(i);
            cl[i].push_back(x);
        }
    }

    //adj is classes to nodes
    //cl is nodes to classes

    queue<pii> q;

    fill(distances,distances+n,1e12);
    distances[0] = 0;
    
    for(int i : cl[0]) q.push({i,0});

    while(!q.empty()){
        int cla = q.front().first;
        int node = q.front().second;

        q.pop();

        for(int child:adj[cla]){
            //find nodes who share a class

            if(distances[child] > distances[node] + abs(a[child]-a[node]) + k){
                distances[child] = distances[node] + abs(a[child]-a[node]) + k;

                for(int i : cl[child]) q.push({i,child});
                
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << (distances[i] == 1e12 ? -1 : distances[i]) << "\n";
    }





}