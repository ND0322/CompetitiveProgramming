#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1e8;

int n1,n2,k1,k2;

vector<vector<vector<vector<int>>>> dp;

int solve(int cap1,int cap2,int last1, int last2){
    if(last1 > k1 || last2 > k2 || cap1 < 0 || cap2 < 0){
        return 0;
    }
    if(!cap1&& !cap2){
        return 1;
    }

    if(dp[cap1][cap2][last1][last2] == -1){
        dp[cap1][cap2][last1][last2] = (solve(cap1-1,cap2,last1+1,0) + solve(cap1,cap2-1,0,last2+1)) % MOD;
    } 
    return dp[cap1][cap2][last1][last2];

}

int main(){
    cin >> n1 >> n2 >> k1 >> k2;
    dp = vector<vector<vector<vector<int>>>>(n1+1,vector<vector<vector<int>>>(n2+1,vector<vector<int>>(k1+1,vector<int>(k2+1,-1))));
    cout << solve(n1,n2,0,0) % MOD << "\n";
}