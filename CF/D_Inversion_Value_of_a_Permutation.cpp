#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool dp[35][1005];

int rebuild[35][1005];

/*
compl count

sort subarray of length n contributes n * (n-1)/2

dp[mx][cap]


4 3 1 2
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        k = (n * (n+1))/2 - k;


        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                for(int l = 1; l <= i; l++){
                    
                    if(j - ((l+1) * l) / 2 < 0) continue;
                    dp[i][j] |= dp[i-l][j-((l+1) * l) / 2];
                    if(dp[i-l][j-((l+1) * l) / 2]) rebuild[i][j] = l;
                }
            }
        }

        if(!dp[n][k]){
            cout << "0\n";
            continue;
        }

        int i = n;
        int j = k;

        while(i){
            for(int l = i - rebuild[i][j] + 1; l <= i; l++) cout << l << " ";
            int p = rebuild[i][j];

            i -= p;
            j -= ((p+1) * p) / 2;
        }

        cout << "\n";
    }
}