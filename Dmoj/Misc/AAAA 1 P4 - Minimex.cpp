#include <bits/stdc++.h>
#include <iostream>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;



const int MAXN = 305;
const int MOD = 1e9+7;

#define int long long

int n, m, a[MAXN][MAXN], dp[MAXN*2][MAXN][MAXN], psa[MAXN*2][MAXN][MAXN], fact[MAXN*MAXN], factinv[MAXN*MAXN];

pair<int,int> pos[MAXN*MAXN];
bool in[MAXN*MAXN];
/*
consider sub 1

for each i the minimum size subarray 

n^4

dp state 
current in set, current not in set, current size 

we can add a row on every direction 
and fill with non mex things 

for full
current position from 0 to n, current size

we can calculate the number of open slots in the current submatrix
when we get to a in set we can transition to adding a row in any direction
*/

int fastpow(int a, int b){
    long long ans = 1;
    while(b > 0){
        if(b&1) ans = (ans * a) % MOD;
        a = (a*a) % MOD;
        b >>=1;
    }
    return ans;
}

int minv(int x){
    return fastpow(x, MOD-2);
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            pos[a[i][j]] = {i,j};
        }
    }

    vector<int> b;

    pair<int,int> tl = pos[0];
    pair<int,int> br = pos[0];
    in[0] = 1;
    b.push_back(0);
    fact[0] = 1;
    factinv[0] = minv(1);
    for(int i = 1; i <= n * m; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        factinv[i] = minv(fact[i]) % MOD;
        if(tl.first <= pos[i].first && pos[i].first <= br.first && tl.second <= pos[i].second && pos[i].second <= br.second) continue;
        in[i] = 1;
        b.push_back(i);
        tl.first = min(tl.first, pos[i].first);
        tl.second = min(tl.second, pos[i].second);
        br.first = max(br.first, pos[i].first);
        br.second = max(br.second, pos[i].second);
    }


    dp[1][1][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++) psa[1][i][j] = 1;
    }

    for(int i = 2; i < b.size(); i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                //move both
                dp[i][j][k] = 4 * psa[i-1][j-1][k-1];
                //2 sides and j spots 
                dp[i][j][k] = (dp[i][j][k] + (2 * j * (psa[i-1][j][k-1] - psa[i-1][j-1][k-1] - psa[i-1][j][0] + psa[i-1][j-1][0] + MOD) % MOD) % MOD) % MOD;
                dp[i][j][k] = (dp[i][j][k] + (2 * k * (psa[i-1][j-1][k] - psa[i-1][j-1][k-1] - psa[i-1][0][k] + psa[i-1][0][k-1] + MOD) % MOD) % MOD) % MOD;
                dp[i][j][k] = (dp[i][j][k] * fact[k * j - b[i-1] - 1]) % MOD;
                dp[i][j][k] = (dp[i][j][k] * factinv[k*j - b[i]]) % MOD;
            

                psa[i][j][k] = (psa[i][j-1][k] + psa[i][j][k-1] - psa[i][j-1][k-1] + dp[i][j][k] + MOD) % MOD;
            }
        }
    }

    cout << dp[b.size()-1][n][m] << "\n";




    




}