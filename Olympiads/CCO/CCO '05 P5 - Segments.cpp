#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e4+5;

int n,l[MAXN],r[MAXN],dp[MAXN][2];

//0 finish at the right
//1 finist at the left


int main(){
    cin >> n;


    l[0] = 1;
    r[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][0] + abs(l[i-1] - r[i]),dp[i-1][1] + abs(r[i-1] - r[i])) + r[i] - l[i] + 1;
        dp[i][1] = min(dp[i-1][0] + abs(l[i-1] - l[i]),dp[i-1][1] + abs(r[i-1] - l[i])) + r[i] - l[i] + 1;
    }

    cout << min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]) - 1 << "\n";

}