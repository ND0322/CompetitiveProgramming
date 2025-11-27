#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
upper bound on answer is popcount n
*/

long long fact[20];
int main(){
    fact[1] = 1;

    for(int i = 2; i <= 15; i++) fact[i] = fact[i-1] * i;
    
    int tt; cin >> tt;

    while(tt--){
        long long n; cin >> n;

        int ans = 1e9;
        for(int i = 0; i < 1<<15; i++){
            if((i&1) || (i & 2)) continue;

            long long tmp = n;

            for(int j = 1; j <= 15; j++){
                if((i >> (j-1)) & 1) tmp -= fact[j];
            }

            if(tmp < 0) continue;


            ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(tmp));
        }

        cout << ans << "\n";
    }
}