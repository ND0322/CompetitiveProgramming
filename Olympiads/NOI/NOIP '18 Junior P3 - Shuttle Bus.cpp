#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int n,m,a[MAXN],dp[MAXN][MAXN][MAXN*100],psa[MAXN];










int main(){
    cin >> n >> m;

    

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    psa[n+1] = psa[n];

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            for(int k = 0; k <= i*m; k++){
                int opt1 = dp[i+1][j][max(0,k-())]
            }
        }
    }

  

    

   


    
   

   

    

   




    




   

    




}