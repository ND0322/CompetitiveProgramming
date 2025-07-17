#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[10][2][2];

string a,b;

int f(int i, bool g, bool l){
    if(i == (int)a.size()) return 0;

    if(dp[i][g][l] != -1) return dp[i][g][l];

    dp[i][g][l] = 1e9;

    for(int j = 0; j <= 9; j++){


        
        if(j < a[i] - '0' && !g) continue;
        if(j > b[i] - '0' && !l) continue;


        
        dp[i][g][l] = min(dp[i][g][l], f(i+1, g | (j > a[i] - '0'),l | (j < b[i] - '0')) + (a[i] - '0' == j) + (b[i] - '0' == j)); 
        
       
    }

    return dp[i][g][l];
    
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> a >> b;

        a = '.' + a;
        b = '.' + b;


        memset(dp, -1, sizeof(dp));

        cout << f(1, 0,0) << "\n";


        
    }
}