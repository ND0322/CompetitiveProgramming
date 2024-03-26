#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 405;

int n,cap, val[MAXN][MAXN], dp[MAXN][MAXN], psa[MAXN];

bool a[MAXN];

//calc val with range dp assuming u flip all heads possible
//dp is current i, cap 

int main(){
    string s; cin >> s;

    n = s.size();

    cin >> cap;

    for(int i = 1; i <= n; i++){
        a[i] = (s[i-1] == 'H');
        psa[i] = a[i] + psa[i-1];
        val[i][i] = a[i];
    }


    for(int i = n; i >= 1; i--){
        for(int j = i+1; j <= n; j++){
            for(int k = i; k <= j; k++){
                if(a[k]) val[i][j] = max(val[i][j], val[i][k-1] + val[k+1][j] + j - i + 1);
                //if(a[k] && i == 1 && j == n) cout << k << " " << val[i][k-1] + val[k+1][j] + j - i + 1 << "\n";
            }
        }
    }

    



    //cout << val[1][5] << "\n";
    //cout << val[1][6] << "\n";

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= cap; j++){
            dp[i][j] = dp[i+1][j];

            for(int k = i; k <= n; k++){
                if(j - (psa[k] - psa[i-1]) >= 0) dp[i][j] = max(dp[i][j], dp[k+1][j - (psa[k] - psa[i-1])] + val[i][k]);
                
            }
        }
    }

    cout << dp[1][cap] << "\n";
}