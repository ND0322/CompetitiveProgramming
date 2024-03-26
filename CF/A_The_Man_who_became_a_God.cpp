#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> dp;
int n,k,arr[105];


int solve(int i, int l){

    
    if(l < 0){
        return 1e6;
    }
    if(i == n && l){
        return 1e6;
    }
    else if(i == n && l == 0){
        return 0;
    }

    

    if(dp[i][l] == -1){
        dp[i][l] = min(solve(i+1,l) + abs(arr[i-1] - arr[i]), solve(i+1,l-1));
        //cout << i << " " << l << endl;
        //cout << solve(i+1,l) + abs(arr[i-1] - arr[i]) << " " << solve(i+1,l-1) << endl;

        //cout << abs(arr[i-1] - arr[i]) << endl;
    }
    return dp[i][l];

    
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        dp = vector<vector<int>>(n,vector<int>(k+1,-1));

        cout << solve(1,k-1) << "\n";

        

        

       
    }
}