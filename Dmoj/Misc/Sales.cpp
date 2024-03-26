#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e4+5;

int n, cap, q, c[MAXN],v[MAXN], dp[55],freq[55][1005];

int main(){


    //this is bs
    cin >> cap >> n >> q;

    

    for(int i = 1; i <= n; i++){
        cin >> c[i] >> v[i];
        
        }



    for(int i = 0; i < q; i++){
        int x,y,l,r; cin >> x >> y >> l >> r;

        c[x] = y;
        

       

        //obviously wont pass

       

       //remove the factor of n
       
       //use freq array to keep track of objects instead of having a factor of n

       //max(v) * cap^2 * q is too slow;


       
       for(int i = 0; i <= 50; i++){
            for(int j = 0; j <= 1000; j++){
                freq[i][j] = 0;
            }
        }
       

        

        int big = 0;

        for(; l <= r; l++){
            freq[c[l]][v[l]]++;
            big = max(big,v[l]);
        }


    
        fill(dp,dp+cap+1,0);

        

        for(int j = cap; j >= 1; j--){

            int mx = cap/j;
            //we can add at most mx objects with weight j

            

            
            
            for(int k = big; k >= 1; k--){

                
               
                while(mx && freq[j][k]){

                    //this removes the factor of n here
                    
                    freq[j][k]--;
                    mx--;
                    for(int i = cap; i >= j; i--){
                        dp[i] = max(dp[i],dp[i-j] + k);

                        //j is the cap of the cur object, k is the val we iterate through freq like normal knapsack
                        
                    }
                }

                if(!mx) break;
                    
            }

            //still might be too slow
                
            
        }

        cout << dp[cap] << "\n";

       

        


    }

   

    
}