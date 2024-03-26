#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n;




int construct(vector<std::vector<int>> p){
    n = p.size();

    vector<vector<int>> adj(n, vector<int>(n,0));

    for(int i = 0; i < n-1; i++) adj[i][i+1] = 1;
    build(adj);

    return 1;
}

