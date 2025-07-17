#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//green must form a CC of its own as well 
//after deciding green there will be 2^number of adjacent nodes to green
//f(u) = 2 + PI f(v)
//f(leaf) = 3
//something to do with number of leaves 
//casework
//prime factorize or some shit
//we can get 3^a * 5^b & 7^c etc.. + 2k
//where k is nonnegative 
//+2k is not important as it will be included in the 3^a etc
//3 ^ a * 5^b * 7^c
//prime odd numbers

const int MAXN = 5e5+5;

int dp[MAXN];

int main(){
    int tt; cin >> tt;

    for(int i = 3; i < MAXN; i += 2){
        dp[i] = dp[i-2] + 1;

        for(int j = 3; j <= sqrt(i); j++){
            if(i % j != 0) continue;

            dp[i] = min(dp[i], dp[j] + dp[i/j]);
        }
    }
    while(tt--){
        int n; cin >> n;

        if(n % 2 == 0){
            cout << "-1\n";
            continue;
        }

        cout << dp[n]+1 << "\n";

       

        
    }

    
 
}