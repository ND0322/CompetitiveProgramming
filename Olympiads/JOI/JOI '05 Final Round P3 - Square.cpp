#include <bits/stdc++.h>
#include <iostream>

using namespace std;


vector<vector<int>> dp[35][35];

vector<vector<int>> f(int i, int par){
    if(i <= 0) return {};

    if(dp[i][par].size()) return dp[i][par];

    if(i <= par) dp[i][par].push_back({{i}});

    for(int j = min(par, i); j >= 1; j--){
        for(auto k : f(i-j, j)){
            dp[i][par].push_back({j});
            for(int l : k) dp[i][par].back().push_back(l);
        }
    }

    return dp[i][par];
}

int main(){
    int n; cin >> n;
    for(auto i : f(n, n)){
        for(int j = 0; j < i.size(); j++) cout << i[j] << (j < i.size()-1 ? " " : "");
        cout << "\n";
    }
}