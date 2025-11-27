#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//find next with monotnic stack
//for second half either transition to equal
//add 2 ^ length


const int MAXN = 5005;
const int MOD = 998244353;

#define int long long


int dp[MAXN][2];

int binpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a*a) % MOD;
        b >>=1;
    }
    return res;
}




int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        memset(dp, 0, sizeof(dp));

        vector<int> a(n+1);

        map<int,int> l, r;

        int mx = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int i = n;

        while(1){
            for(int j = i-1; j >= 1; j--){
                if(a[j] > a[i]){
                    r[a[j]] = a[i];
                    i = j;
                    break;
                }
            }

            if(a[i] == mx) break;
        }

        for(int i = 1; i <= n; i++) cout << r[i] << " ";
        cout << "\n";
        i = 1;

        while(1){
            for(int j = i+1; j <= n; j++){
                if(a[j] > a[i]){
                    l[a[i]] = a[j];
                    i = j;
                    break;
                }
            }

            if(a[i] == mx) break;
        }

        for(int i = 1; i <= n; i++){
            if(a[i] == a[n]) dp[i][1] = 1;
        }
        for(int i = n-1; i >= 1; i--){

            

            int cnt = 0;

            for(int j = i+1; j <= n; j++){
                if(a[j] <= a[i]) cnt++;
                if(a[j] == l[a[i]]) dp[i][0] = (dp[i][0] + (dp[j][l[a[i]] == mx] * binpow(2, cnt)) % MOD) % MOD;
                    
                
            }

            cnt = 0;
            int cnt2 = 0;
            for(int j = i+1; j <= n; j++){
                if(a[j] < r[a[i]]) cnt++;
                if(a[j] < a[i]) cnt2++;
                if(a[j] == r[a[i]]) dp[i][1] = (dp[i][1] +  (dp[j][1] * binpow(2, cnt)) % MOD) % MOD;
                if(a[j] == a[i]) dp[i][1] = (dp[i][1] + (dp[j][1] * binpow(2, cnt2))) % MOD;
            }
        }

        for(int i = 1; i <= n; i++) cout << dp[i][0] << " ";
        cout << "\n";
        for(int i = 1; i <= n; i++) cout << dp[i][1] << " ";
        cout << "\n";
       
        int sm = 0;

        for(int i = 1; i <= n; i++) sm = (sm + dp[i][mx == a[1]] * (a[i] == a[1]))%MOD;

        cout << max(sm, 1LL) << "\n";


        
    }
}