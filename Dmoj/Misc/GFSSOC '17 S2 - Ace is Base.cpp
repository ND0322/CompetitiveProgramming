#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

pair<int,bool> dp[505][2];

vector<int> digits;

pair<int,bool> solve(int i, bool has){
    if(i >= digits.size()) return {has,has};

    if(dp[i][has] == {0}){
        dp[i][has] = {0,0};

        for(int j = 0; j <= digits[i]; j++) dp[i][has] += solve(i+1, has | (j == 10 || j == 12 || j == 14)) + 1;
    }

    return dp[i][has];
}
int32_t main(){
    int a, b; cin >> a >> b;

    a--;

    int f = 0;
    int cnt = 0;

    while(a){
        digits.push_back(a%16);
        cnt++;
        a/=16;
    }

    memset(dp,-1,sizeof(dp));

    cout << solve(0,0) << "\n";

    

    


}