#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,dp[MAXN][3][2],a[MAXN];

//i,supported by last, not supported or supported by next, supporting last

int main(){
    

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];



       
    }

    

    a[n] = 3;
    dp[n-1][0][0] = 0;
    dp[n-1][1][0] = 1;
    dp[n-1][1][1] = 1;
    dp[n-1][2][0] = 1e9;
    dp[n-1][2][1] = 1e9;
    
    if(a[n-1] == 0){
        dp[n-1][1][1] = 1e9;
        
    }
    
    
   

    
    for(int i = n-2; i >= 0; i--){

       

       if(!a[i]){
        dp[i][0][1] = 1e9;
        dp[i][1][1] = 1e9;
        dp[i][2][1] = 1e9;
        dp[i][0][0] = min(dp[i+1][1][0],dp[i+1][2][0]);
        dp[i][1][0] = min(1+dp[i+1][1][0],1+dp[i+1][2][0]);
        dp[i][2][0] = min(dp[i+1][1][1],dp[i+1][2][1]);

        //if(i == 1) cout << dp[i+1][1][1] << " " << dp[i+1][2][1] << "\n";

       
        

        

        
        
        
       }

       if(a[i] == 1){
        dp[i][1][0] = min({1+dp[i+1][1][0],1+dp[i+1][2][0],1+dp[i+1][0][0]});
        dp[i][1][1] = min({1+dp[i+1][1][0],1+dp[i+1][2][0]});

        dp[i][0][0] = min({dp[i+1][1][0],dp[i+1][2][0],dp[i+1][0][0]});
        dp[i][0][1] = min(dp[i+1][1][0],dp[i+1][2][0]);

        dp[i][2][0] = min(dp[i+1][1][1],dp[i+1][2][1]);
        dp[i][2][1] = min(dp[i+1][1][1],dp[i+1][2][1]);

        //if(i == 2) cout << dp[i+1][1][1] << " " <<dp[i+1][2][1] << endl;

       }

       if(a[i] == 2){
        dp[i][1][0] = min({1+dp[i+1][1][0],1+dp[i+1][2][0],1+dp[i+1][0][0]});
        dp[i][1][1] = min({1+dp[i+1][1][0],1+dp[i+1][2][0],1+dp[i+1][0][0]});

        dp[i][0][0] = min({dp[i+1][1][0],dp[i+1][2][0],dp[i+1][0][0]});
        dp[i][0][1] = min({dp[i+1][1][0],dp[i+1][2][0],dp[i+1][0][0]});

        dp[i][2][0] = min(dp[i+1][1][1],dp[i+1][2][1]);
        dp[i][2][1] = min(dp[i+1][1][1],dp[i+1][2][1]);
       }
rec

       

        //1+0+0+1+0+0+1+1+1
        

         
       

       
      

       
       //not supported, supporting last
       //if a[i] = 0, it is impossible to support last. Otherwise, we can either support or not support next;


       //dp[i][1][1] = (a[i] == 0 ? 1e9 : min({1+dp[i+1][a[i] -1 >= 1 ? 0 : 1][0],1+dp[i+1][2][0],dp[i+1][1][1]}))

       
        
    }

    //cout << dp[0][1][0] << " " << dp[0][2][0] << "\n";

    
    cout << min({dp[0][1][0],dp[0][2][0]}) << "\n";



    

  


}