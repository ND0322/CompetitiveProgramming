#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN][2], psa[MAXN][2], dp[MAXN][2];

/*
property that average of the averages is equal to the total average
subtract the total average from each cell so its the same as finding sum 0
dp is i, row we're working on
*/

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];

    for(int i = 1; i <= n; i++){
        psa[i][0] = psa[i-1][0] + a[i][0];
        psa[i][1] = psa[i-1][1] + a[i][1];
    }

    for(int i = n; i >= 1; i--){
        dp[i][0] = dp[i][1] = max(dp[i+1][1], dp[i+1][0]);

        //create a and end a new boi on the other row
        for(int j = i+1; j <= n; j++){
            if(!(psa[j] - psa[i-1])){
                dp[i][0] = max(dp[i][0], dp[j+1][1] + 1);
                dp[i][1] = max(dp[i][1], dp[j+1][0] + 1);
            }
        }

        //complete this boi using the other row
 



        

    }
}

