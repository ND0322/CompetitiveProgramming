#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n,k, m, psa[MAXN], dp[MAXN];

char a[MAXN];

//if we're in the water we greedy for the nearest log
//check that no crocodiles in between and that distance is within k
//if we in log we can bruteforce it
//checking requires psas

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m >> k;
        
        set<int> logs;

        for(int i = 0; i <= n+1; i++) dp[i] = 1e9;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 'L') logs.insert(i);
        }        



        a[n+1] = 'L';
        a[0] = 'L';
        logs.insert(n+1);
        logs.insert(0);
        dp[n+1] = 0;

        for(int i = n; i >= 0; i--){
            dp[i] = 1e9;
            if(a[i] == 'C') continue;
            if(a[i] == 'L'){
                for(int j = 1; j <= m; j++){
                    if(i+j > n+1) break;
                    dp[i] = min(dp[i],dp[i+j]);

                }
            }
            else dp[i] = dp[i+1] + 1;
        }

        cout << (dp[0] <= k ? "YES\n" : "NO\n");
    }
}