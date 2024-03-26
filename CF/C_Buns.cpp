#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 15;


int n,m,ci,di,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
vector<vector<int>> dp;


int solve(int i, int cap){
    //cout << i << " " << cap << endl;
    if(i == m){
        return di * (cap / ci); 
    }

    if(dp[i][cap] == -1){
        for(int j = 0; j * b[i] <= a[i] && cap - c[i] * j >= 0; j++){
            dp[i][cap] = max(dp[i][cap],solve(i+1,cap-c[i]*j) + j * d[i]);
        }
    }
    return dp[i][cap];

    
}

int main(){
    cin >> n >> m >> ci >> di;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    dp = vector<vector<int>>(m+1,vector<int>(n+1,-1));
    cout << solve(0,n) << "\n";
}

