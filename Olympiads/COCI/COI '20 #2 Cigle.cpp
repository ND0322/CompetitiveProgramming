#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n, dp[MAXN][MAXN][2], a[MAXN], psa[MAXN];

//1 for suffix 

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) psa[i] = psa[i-1];

    //current r 
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++){

            
            //prefix
            set<int> s;

            for(int k = j; k <= i; k++) s.insert(psa[k] - psa[j-1]);
            int cnt = 0;
            for(int k = i+1; k <= n; k++){
                cnt += (s.find(psa[k] - psa[j-1]) != s.end());
                dp[j][i][0] = max(dp[j][i][0], dp[i][k][1] + cnt);
            }


            s.clear();
            for(int k = j; k <= i; k++) s.insert(psa[i] - psa[k-1]);
            int cnt = 0;
            for(int k = i+1; k <= n; k++){
                cnt += (s.find(psa[k] - psa[i-1]) != s.end());
                dp[j][i][0] = max(dp[j][i][0], dp[i][k][1] + cnt);
            }
        }
    }
}