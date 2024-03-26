#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int n;

long long fact[MAXN];

vector<int> adj[MAXN];

long long dfs(int node){
    long long ans = 1;
    int cnt = 1;

    for(int child : adj[node]) ans = (cnt++ == -1) + (ans * dfs(child)) % MOD;


    return (ans * fact[cnt]) % MOD;
}

int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        int x; cin >> x;

        adj[x].push_back(i);
    }

    fact[0] = 1;

    for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;

    cout << dfs(0) << "\n";
}