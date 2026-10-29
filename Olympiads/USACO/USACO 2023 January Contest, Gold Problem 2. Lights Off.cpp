#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 20;

int n;

bool dp[1<<MAXN][MAXN+5];

/*
consider not doing any toggles between operations 

basically we will have string s

let ti denote t shifted i times
s
xor t0
xor t1
xor t2
...
xor tn

now we can do it again to cancel

so it is only every viable to do it 2n times at most
now we want to find an i such that after shifting i times, we can toggle exactly i bits to make it 0
so we need i >= popcount && the parity to match


wrong
similar apporach but we instead check if the final xor is constructable from a series of circular subarrays
We can use dp to find reachable masks in 2^n * n^2
Bitset if that is too slow 
*/

int cshift(int x){

    bool p = x & 1;
    x >>= 1;
    x += p <<(n-1);
    return x;
    
}

int main(){
    int tt; cin >> tt >> n;

    dp[0][0] = 1;



    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (1<<n); j++){
            int m = (1<<i)-1;

            

            for(int k = 0; k < n; k++){
                dp[j][i] |= dp[j ^ m][i-1];
                
                m = cshift(m);
            }

            
        }
    }

    while(tt--){
        string s, t; cin >> s >> t;

        int a = 0;
        int b = 0;

        for(int i = 0; i < n; i++) a += (s[n-i-1] - '0') * (1<<i);
        for(int i = 0; i < n; i++) b += (t[n-i-1] - '0') * (1<<i);

        if(!a){
            cout << "0\n";
            continue;
        }

        

        //running xor
        int ans = 1e9;
        for(int i = 1; i < 2*n; i++){
            a ^= b;

            if(dp[a][i]){
                ans = i;
                break;
            }
            b = cshift(b);
            
        }

        cout << ans << "\n";
    }



    
}