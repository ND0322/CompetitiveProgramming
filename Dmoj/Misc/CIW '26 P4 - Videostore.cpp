#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

int n,m, t, k, dp[MAXN][MAXN], psa[MAXN];

pair<pair<int,int>, int>> ranges[MAXN];
int main(){
    cin >> n >> m >> t >> k;

    for(int i = 1; i <= n; i++) cin >> ranges[i].first.second >> ranges[i].first.first >> ranges[i].second;

    for(int i = 1; i <= m; i++) cin >> psa[i];
    for(int i = 1; i <= m; i++) psa[i] += psa[i-1];


    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            for(int k = i+1; k <= n; k++){
                
            }
        }
    }


}