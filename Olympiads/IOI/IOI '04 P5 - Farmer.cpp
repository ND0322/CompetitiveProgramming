#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXM = 150005;
const int MAXN = 4005;

int n,m, cap, dp[2][MAXM];

pair<int,int> a[MAXN];



/*
notice that it is always optimal to completely take a field when possible
*/

int main(){
    cin >> cap >> n >> m;


    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = 0;
    }

    for(int i = 1; i <= m; i++){
        cin >> a[i+n].first;
        a[i+n].second = 1;
    }


    for(int i = n+m; i >= 1; i--){
        for(int j = 0; j <= cap; j++){
            dp[0][j] = dp[1][j];
            if(j >= a[i].first) dp[0][j] = max(dp[0][j], dp[1][j - a[i].first] + a[i].first - a[i].second); 
            else dp[0][j] = max(dp[0][j], dp[1][0] + j - 1);

        }
        
        for(int j = 0; j <= cap; j++){
            dp[1][j] = dp[0][j];
            dp[0][j] = 0;
        }
    }

    cout << dp[1][cap] << "\n";
}