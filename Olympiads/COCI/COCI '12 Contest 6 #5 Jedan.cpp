#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;
const int MOD = 1e9+7;

/*
dp is i, height
only keep track of last dp
*/
int n,a[MAXN];

long long dp[MAXN],last[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    last[0] = (a[n] <= 0);


    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j <= n; j++){
            if(a[i] != -1 && j != a[i]) continue;

            

            dp[j] = (last[j] + last[j+1]) % MOD;

            if(j > 0) dp[j] = (dp[j] + last[j-1]) % MOD;

        }


        for(int j = 0; j <= n; j++){
            last[j] = dp[j];
            dp[j] = 0;
        }
    }

    cout << last[0] << "\n";
}