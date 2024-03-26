#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int r,l, ori[35];

bool dp[35][1<<8];



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> r >> l;

    for(int i = r; i >= 1; i--){

        int cur = 0;
        for(int j = l-1; j >= 0; j--){
            int x; cin >> x;
     
           
            cur += x<<j;

        }
        
        ori[i] = cur;
        dp[i][cur] = 1;
        
    }


    

    

    for(int i = r-1; i >= 1; i--){
        for(int j = 0; j < 1<<l; j++){

           
    
            dp[i][j] |= dp[i+1][j^ori[i]];
        }
    }

   

    

    int ans = 0;

    //001 100 111 110

    for(int i = 0; i < 1<<l; i++){
        ans += dp[1][i];

        //cout << bitset<3> (i) << "\n";

        
    }
    cout << ans << "\n";
}