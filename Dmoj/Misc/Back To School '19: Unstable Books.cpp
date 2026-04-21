#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n, dp[MAXN][2][2], a[MAXN];

/*
did we swap the last one 
number of local min max 
*/

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n == 1){
        cout << "1\n";
        return 0;
    }

    for(int i = n/2 ; i>=1 ;i--){
        for(int f = 0; f < 2; f++){
            for(int s = 0; s < 2; s++){

                if(i == 1){
                    dp[i][f][s] = min(dp[i+1][s][1], dp[i+1][s][0]);
                    continue;
                }


                int l1 = {f ? a[n-i+2] : a[i-1]};
                int l2 = {s ? a[n-i+1] : a[i]};
                int r1 = {f ? a[i-1] : a[n-i+2]};
                int r2 = {s ? a[i] : a[n-i+1]};



                //no swap
                int l3 = a[i+1];
                int r3 = a[n - i];

                if(i == n/2 && s){
                    l3 = a[n-i];
                    r3 = a[i+1];
                }
                

                //cout << i << " " << f << " " << s << " " << l1 << " " << l2 << " " << l3 << " " << r3 << " " << r2 << " " << r1 << "\n";
                //cout << ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3)) << "\n";

                
                
                dp[i][f][s] = dp[i+1][s][0] + ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3));

                //cout << dp[i+1][s][0] + ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3)) << "\n";
                //swap 
                if(i == n/2) continue;

                l3 = a[n-i];
                r3 = a[i+1];

                //cout << "swap\n";

                //cout << i << " " << f << " " << s << " " << l1 << " " << l2 << " " << l3 << " " << r3 << " " << r2 << " " << r1 << "\n";
                //cout << ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3)) << "\n";

          

                dp[i][f][s] = min(dp[i][f][s], dp[i+1][s][1] + ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3)));
                //cout <<  dp[i+1][s][1] + ((l1 < l2 && l2 > l3) || (l1 > l2 && l2 < l3)) + ((r1 < r2 && r2 > r3) || (r1 > r2 && r2 < r3)) << "\n";
            }
        }
    }

    cout << min(dp[1][0][0],dp[1][0][1])+1 + ((n&1) ? ((a[n/2] < a[n/2+1] && a[n/2+1] > a[n/2+2]) || (a[n/2] > a[n/2+1] && a[n/2+1] < a[n/2+2])) : 0)<< "\n";
    
}