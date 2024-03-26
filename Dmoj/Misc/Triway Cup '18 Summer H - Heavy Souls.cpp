#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//bitmask
//num words with that alphabet
int n, dp[1<<20];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int alph = 0;

        string s; cin >> s;

        for(int i = 0; i < s.size(); i++) alph |= (1<<((int)s[i] - 97));

        dp[alph]++;
    }


    for(int j = 0; j < 20; j++){

        for(int i = 0; i < (1<<20); i++){
            
            //try adding each letter

            if(!(i&(1<<j))) dp[i] += dp[i|(1<<j)];
        }
    }

    int ans = 1e9;

    for(int i = 0; i < (1<<20); i++){
        if(dp[i] == 1) ans = min(ans,__builtin_popcount(i));
    }

    cout << (ans != 1e9 ? ans : -1) << "\n";
    
}