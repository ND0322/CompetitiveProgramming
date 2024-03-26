#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MAXM = 2e4+5;
const int INF = 1e9;

int n,e,dp[MAXN][MAXM];



//cur room, this many total
//for each number of people j
//j < b
//cant open the right door
//place less than a in the rooms before this one and place j in this
//or place all the people in the rooms before
//if j < a+b but at least b
//they can open one of the two doors
//we allow them to open the right door by placing b in the room
//but we put less than a in the prefix before this so it probably hopefully cant open the left door
//otherwise both doors can be open at the same time
//we cant place any of these in the room so we place them in the prefix



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int n,e; cin >> n >> e;

    for(int i = 0; i < e; i++) dp[0][i] = i;
    for(int i = e; i < MAXM; i++) dp[0][i] = -INF;

    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;

        int best = 0;

        for(int j = 0; j < a; j++) best = max(best, dp[i-1][j]);
        for(int j = 0; j < MAXM; j++){
            if(j < b) dp[i][j] = max(dp[i-1][j+a], best + j);
            if(j >= b && j < a+b) dp[i][j] = b + dp[i-1][j-b];
            if(j >= a+b) dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < MAXM; i++) ans = max(ans, dp[n-1][i]);
    cout << ans << "\n";

    

    
}