#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;


int n,m,k, a[MAXN], b[MAXN], dp[2][MAXN*MAXN];

/*
sub 2 -> iterate all masks 

n * k - min(n, b[i])

current item, n * k capacity, total capacity 

smallest dp value greater than 0
smallest sum b[i] - sm 
*/
int main(){
    cin >> n >> m >> k;

    int sm = 0;
    int cap = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sm += a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        cap += b[i];
    }


    if(m < k){
        cout << "Impossible\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(a[i] < k){
            cout << "Impossible\n";
            return 0;
        }
    }


    for(int i = 0; i <= cap; i++) dp[0][i] = -1e9;
    

    dp[0][0] = 0;


    for(int i = m ; i >= 1; i--){
        for(int j = 0; j <= cap; j++){

            dp[1][j] = dp[0][j];

            //take
            if(j >= b[i]) dp[1][j] = max(dp[1][j], dp[0][max(0, j - b[i])] + min(n, b[i]));
        }
        
        for(int j = 0; j <= cap; j++) dp[0][j] = dp[1][j];
            
        




    }

    int ans = 1e9;

    for(int i = 0; i <= cap; i++){
        if(dp[0][i] >= n * k && i >= sm) ans = min(ans, i - sm);
        
    }

    if(ans == 1e9) cout << "Impossible\n";
    else cout << ans << "\n";
    


}