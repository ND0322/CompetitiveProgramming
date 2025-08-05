#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

//decompose the string into some blocks of m and o
//work backwards
//the last m will have suffix C K options
//in the full problem no block of Os will ever have length > n
//We will have some overflow zeros that apply to the next string


long long fact[MAXN], k,n,l, r[MAXN];

long long quickpow(long long x, int y)
{
    long long res = 1;
 
    x = x % MOD;
 
    while (y > 0) {
 
        
        if (y & 1)
            res = (res * x) % MOD;
 
        
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}


int32_t main(){
    cin >> k >> n >> l;

    string s; cin >> s;

    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;

    s = "." + s;

    int cnt = 0;
    int ms = 0;

    long long ans = 1;
    for(int i = n; i >= 1; i--){
        if(s[i] == 'O'){
            cnt++;
            continue;
        }
        ms++;

        r[i] = cnt;
        long long res = (fact[cnt] * quickpow(((fact[k] * fact[cnt-k]) % MOD), MOD-2)) % MOD;
        cnt -= k;

        if(cnt < 0){
            ans = 0;
            break;
        }

        ans = (ans * res) % MOD;
    }

    if((n - ms) != ms * k){
        cout << "0\n";
        return 0;
    }
    cout << quickpow(ans, l) << "\n";

}