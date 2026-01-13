#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 20;
int n, dp[1<<MAXN], cost[1<<MAXN][MAXN], adj[MAXN][MAXN];
string s;
map<char,int> mp;



/*
model each pair of adjacent as a directed edge

if we keep it, i must come before j in all alphabets
We need to find the minimum number of edges to be removed in order to get a dag
*/

int main(){
    cin >> s;

    n = s.size();

    s = "." + s;

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(s[i]) == mp.end()) mp[s[i]] = cnt++;
    }

    for(int i = 1; i < n; i++) adj[mp[s[i]]][mp[s[i+1]]]++;


    for(int i = 0; i < 1<< (int)mp.size(); i++){
        for(int j = 0; j < 20; j++){
            if(!((i>>j) & 1)) continue;

            for(int k = 0; k < 20; k++){
                if(((i >> k) & 1)) cost[i][j]+= adj[j][k];
            }
        }
    }

    for(int i = 1; i < 1<<(int)mp.size(); i++){

        dp[i] = 1e9;
        for(int j = 0; j < 20; j++){
            if(!((i>>j) & 1)) continue;

            dp[i] = min(dp[i], dp[i ^ (1<<j)] + cost[i][j]);
        }
    }

    cout << dp[(1<<(int)mp.size())-1]+1 << "\n";
}