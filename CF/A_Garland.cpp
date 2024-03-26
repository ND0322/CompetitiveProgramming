#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 105;

int n, a[MAXN], dp[MAXN][MAXN][MAXN][2];

set<int> s;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 1; i <= n; i++){
        cin >> a[i];

        if(a[i]) s.erase(s.find(a[i]));
    }

    int aa = 0;

    for(int i : s) aa += (i&1);
    int bb = (int)s.size() - aa;

    

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= aa; j++){
            for(int k = 0; k <= bb; k++){
                for(int b = 0; b < 2; b++){
                    dp[i][j][k][b] = 1e9;

                    if(a[i]){
                        dp[i][j][k][b] = dp[i+1][j][k][a[i] & 1] + (i != 1) * ((a[i] & 1) != b);
                        continue;
                    }

                    //place odd
                    if(j) dp[i][j][k][b] = dp[i+1][j-1][k][1] + (i != 1) * !b;
                    if(k) dp[i][j][k][b] = min(dp[i][j][k][b], dp[i+1][j][k-1][0] + (i!=1) * (b==1));

                    
                }
            }
        }
    }

    cout << dp[1][aa][bb][0] << "\n";



}