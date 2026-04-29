#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;


#define int long long

int n, m, d, k, u, v;

int MOD;
vector<pair<int,pair<int,int>>> edges;


vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += (a[i][k] * b[k][j]);
                res[i][j] = min(res[i][j], MOD);
            }
        }
    }

    return res;
}


vector<vector<int>> fastpow(vector<vector<int>> a, int b){
    vector<vector<int>> res(n, vector<int>(n));

    for(int i = 0; i < n; i++) res[i][i] = 1;

    while(b > 0){
        if(b&1) res = mult(res, a);
        a = mult(a,a);
        b >>= 1;
    }

    return res;
}


bool f(int x){
    vector<vector<int>> adj(n, vector<int>(n));
    for(auto i : edges){
        if(i.first > x) break;
        adj[i.second.first][i.second.second]++;
        if(i.second.first != i.second.second) adj[i.second.second][i.second.first]++;
    }


    adj = fastpow(adj, d);


    return adj[u][v] >= k;
}


int32_t main(){
    cin >> n >> m >> d >> k >> u >> v;

    MOD = k;

    while(m--){
        int x,y,c; cin >> x >> y >> c;

        edges.push_back({c, {x,y}});
    }

    sort(edges.begin(), edges.end());


    
    

    int lo = 0;
    int hi = 1e9;

    int ans = -1;

    while(lo <= hi){
        int mid =(lo+hi)>>1;

        if(f(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    

    cout << ans << "\n";
}




