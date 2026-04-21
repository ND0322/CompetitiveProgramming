#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int __int128

const int MAXN = 2e5+5;
const int B = 911382629; 
const int MOD = (1LL<<61)-1;


int n, m, freq[27], targ[27];

int hsh[MAXN];

string s, t; 

int fastpow(int a, int b){
    int res = 1;

    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    cin >> s >> t;

    n = s.size();
    m = t.size();

    s = "." + s;
    t = '.' + t;

    for(int i = 1; i <= m; i++) hsh[i] = (hsh[i-1] + (fastpow(B, i-1) * (t[i] - 'a' + 1)) % MOD) % MOD;

    for(int i = 1; i <= n; i++) targ[s[i]-'a']++;

    for(int i = 1; i < n; i++) freq[t[i] - 'a']++;


    set<int> ans;
    for(int i = n; i <= m; i++){
        freq[t[i] - 'a']++;

        bool flag = 1;

        for(int j = 0; j < 26; j++) flag &= (targ[j] == freq[j]);

        if(flag) ans.insert(((hsh[i] - hsh[i-n] + MOD) % MOD * fastpow(fastpow(B, i), MOD-2)) % MOD);
        

        


        freq[t[i-n+1] - 'a']--;
    }

    cout << ans.size() << "\n";

}