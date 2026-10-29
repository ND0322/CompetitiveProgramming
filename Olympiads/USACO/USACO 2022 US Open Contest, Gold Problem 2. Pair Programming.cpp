#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;
const int MOD = 1e9+7;

int dp[MAXN][MAXN][MAXN];

/*
consider no variables 
any choice of constants is fine 
0s also dont matter 

chain of constants are fine 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        string s; cin >> s;
        string t; cin >> t;


        int cnt = 0;

        s = '.' + s;
        t = '.' + t;

        for(int i = 1; i <= n; i++) cnt += s[i] == '+';
        for(int i = 1; i <= n; i++) cnt += t[i] == '+';
        
        for(int i = n+1; i >= 1; i--){
            for(int j = n+1; i >= 1; i--){
                for(int k = 0; k <= cnt; k++){
                
                    if(i == n+1 && j == n+1){
                        dp[i][j] = 0;
                        continue;
                    }



                    if(i != n+1){
                        //0 and 1 are cooked 
                        //strings of 1s are identitcal

                        if(s[i] == '0') dp[i][j][k] = dp[i+1][j][0];

                        
                    }

                    if(j != n+1){
                        if(t[j] == '0') dp[i][j][k] = dp[i+1][j][0];


                    }


                }
            }
        }




    }
}