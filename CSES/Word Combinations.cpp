#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const long long M = 1e9+7;
const int MOD = 1e9+7;
const long long B = 911382629;
const int MAXN = 5005;

#define int long long

int n, k, dp[MAXN], h[MAXN], p[MAXN];

string s;

set<long long> hashes;


int hsh(string s){
    long long val = 0;

    for(int i : s) val = ((val * B) % M + i ) % M;
    

    return val;
}

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> s;

    n = s.size();
    s = '.' + s;
    p[0] = 1;

    for(int i = 1; i <= n; i++){
        h[i] = ((h[i-1] * B) % M + s[i]) % M;
        p[i] =(p[i-1] * B) % M;
    }

    int k; cin >> k;

    while(k--){
        string t; cin >> t;

        hashes.insert(hsh(t));
    }

    dp[n+1] = 1;

    for(int i = n; i >= 1; i--){    
        
        for(int j = i; j <= n; j++){
            int val = (h[j] - (h[i-1] * p[j-i+1]) % M + M) % M;

        

            if(hashes.find(val) != hashes.end()) dp[i] = (dp[i] + dp[j+1]) % MOD;
        }
    }

    cout << dp[1] << "\n";



}