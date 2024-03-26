#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int INF = 1e9;

void solve(){
    int n; cin >> n;

    vector<int> att(n);

    for(int &i:att){
        cin >> i;
    }

    vector<vector<int> > dp(n+1,vector<int>(3,-INF));
    //state is current left and number of attractions

    for(int i = 0; i < n; i++){
        dp[i+1][0] = max(dp[i][0],att[i] + i);
        dp[i+1][1] = max(dp[i][1], dp[i][0] + att[i]);
        dp[i+1][2] = max(dp[i][2], dp[i][1] + att[i] - i);
    }

    cout << dp[n][2] << "\n";

}

int main(){
    int t; cin >> t;


    while(t--){
        solve();
    }
}