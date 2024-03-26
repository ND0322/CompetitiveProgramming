#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

typedef pair<long long, int> pii;

const int MAXN = 5e5+5;

int n, m, a[MAXN];

long long dist[MAXN];

vector<int> adj[MAXN];

//only use l and r

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        adj[a[i]].push_back(i);
        dist[i] = 1e18;
    }

    adj[0].push_back(0);


    for(int i = 1; i <= m; i++){
        int l = 0;

        int r = min(1,(int)adj[i].size()-1);

        for(int child : adj[i-1]){
            while(child > adj[i][r]){
                l = r;
                if(r == (int)adj[i].size()-1) break;
                else r++;
            }

            dist[adj[i][l]] = min(dist[adj[i][l]], dist[child] + abs(child - adj[i][l]));
            dist[adj[i][r]] = min(dist[adj[i][r]], dist[child] + abs(child - adj[i][r]));
        }
    }

    long long ans = 1e18;

    for(int child : adj[m]) ans = min(ans,dist[child]);

    cout << ans << "\n";
    


}