#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
say we kill element i

element i+1 will take i damage
element i+2 will take at most 1 damage depending on element i

ideally we want a suffix of 1s in order to save cost

dp?

we can have dp[i][0] represent this is a 1
dp[i][1] represent this is start of a chunk

maybe need st

3 

2 + 1 + 3 + 1
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1); 

        for(int i = 1;  i<= n; i++) cin >> a[i];

        vector<int> dp(n+5, 1e9);

        dp[n+1] = 0;
        dp[n+2] = 0;
        for(int i = n; i >= 1; i--){
            //start a new stack

            dp[i] = a[i] + max(0LL, a[i+1] - i) + dp[i+2];


            dp[i] = min(dp[i], dp[i+1] + a[i]-1);
        }

        cout << a[1] + max(0LL, a[2] - 1) + dp[3] << "\n";
    }
}