#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int n, k, a[MAXN], dp[MAXN];

/*
similar to the MAT question
I think binary looks like 11001100
*/

int msb(int x){
    return 31 - __builtin_clz(x);
}


int32_t main(){
    cin >> n >> k;

    set<int> s;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        s.insert(x);
    }

    dp[k] = 1;
    for(int i = k-1; i >= 1; i--) dp[i] = (dp[i+1] + dp[i+2] + 1) % MOD;


    int ans = 0;
    for(int x : s){

        if(msb(x) >= k) continue;

        int l = msb(x);
        bool flag = 1;
        while(x){
            if(x % 4 == 0){
                x /= 4;
                if(s.find(x) != s.end()){
                    flag = 0;
                    break;
                }
            }
            else if(x & 1){
                x = (x-1) / 2;
                if(s.find(x) != s.end()){
                    flag = 0;
                    break;
                }
            }
            else break;
        }

        if(flag) ans = (ans + dp[l+1]) % MOD;
    }

    cout << ans << "\n";

   


}