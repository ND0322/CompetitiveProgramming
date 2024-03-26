#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 60;

int r,c,s,b,k,m, weight[MAXN][MAXN],val[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
//just in case




//restarting time 😶

int main(){
    cin >> r >> c >> s >> b >> k >> m;

    


    
    

    for(int i = 0; i < s; i++){
        int t,v,x,y; cin >> t >> v >> x >> y;

        weight[y][x] = t;
        val[y][x] = v;

        

       
        
    }

    for(int i = r; i >= 0; i--){
        for(int j = 1; j <= c; j++){
            for(int c1 = 0; c1 < b; c1++){
                for(int c2 = 1; c2 <= k; c2++){

                    
                    for(int l = max(1,j-m); l <= min(c,j+m); l++){

                        

                        
                        dp[i][j][c1][c2] = max(dp[i][j][c1][c2],dp[i+1][l][c1][c2]);

                        

                        if(val[i+1][l] && c1 - weight[i+1][l] >= 0) dp[i][j][c1][c2] = max(dp[i][j][c1][c2],dp[i+1][l][c1-weight[i+1][l]][c2-1] + val[i+1][l]);
                        

                        
                        
                    }
                }
            }
        }
    }

    


  
    cout << dp[0][1][b-1][k] << "\n";



}