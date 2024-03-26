#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


const int MOD = 998244353;
const int MAXN = 3e5+5;

//complementary counting
//1 1 1 1 1 works for all
//make sure that the other indices all share factors
//for example index 2 must be multiple of 2
//index 3 must be multiple of 3 and 2 for when it shifts
//index 4 must be multiple of 3 and 2, 4 is covered by 2
//5 must be multiple of 3 and 2 and 5
//6 must be multiple of 3 2 and 5

bool prime[MAXN];

int fastpow(long long x, long long y){
    int res = 1;
    x %= MOD;

    if(!x) return 0;
    while(y){
        if(y&1) res = (res * x) % MOD;
        y >>=1;

        x = (x*x)%MOD;
    }
    return res;
}

int32_t main(){
    int n;

    long long m;

    cin >> n >> m;

    memset(prime,1,sizeof(prime));
    for(int i = 2; i*i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i) prime[j] = 0;
        }
    }

    long long tot = 0;

    for(int i = 1; i <= n; i++) tot += fastpow(m%MOD,i);

    long long cnt = 1;
    long long cur = 1;
    long long ans = 0;

    for(int i = 1; i <= n; i++){
        if(cur > m) continue;
        if(prime[i]) cur *= i;
        cnt = (cnt * ((m/cur)%MOD))%MOD;
        ans = (ans+cnt)%MOD;
    }
    
    cout << (tot - ans)%MOD << "\n";



}