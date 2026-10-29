#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 6005;

int n, dp[MAXN][MAXN];

pair<int,int> a[MAXN];

/*
line sweep esque
*/
int main(){
    cin >> n;


    for(int i = 1; i <= n; i++){
        cin >> a[i].first;

        a[i].second = 0;
    }

    for(int i = n+1; i <= 2*n; i++){
        cin >> a[i].first;
        a[i].second = 1;
    }

    sort(a+1, a+2*n+1);
    reverse(a+1,a+2*n+1);

    dp[2*n+1][0] = 1;

    for(int i = 2 * n; i >= 1; i--){
        for(int j = 0; j <= n; j++){
            if(a[i].second){
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                
                continue;
            }

            //dont take
            dp[i][j] = dp[i+1][j];

            //take
            if(j) dp[i][j] += j * dp[i+1][j-1];

        }
    }

    cout << dp[1][0] << "\n";
}