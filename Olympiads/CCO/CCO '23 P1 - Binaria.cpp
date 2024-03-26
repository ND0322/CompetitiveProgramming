#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//a[i] and a[i+1] can differ by at most 1 in a valid sequence
//ans is a[0]! - num differences

const int MAXN = 1e6+5;
const int MOD = 1e6+3;

int n,k, a[MAXN], b[MAXN];

unsigned long long power(unsigned long long x, int y){
    unsigned long long res = 1; 
 
    x %= MOD;
    while (y > 0){
     

        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; 
        x = (x * x) % MOD;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n){
    return power(n, MOD - 2);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,int r){
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
 
    return (fac[n] * modInverse(fac[r]) % MOD* modInverse(fac[n - r]) % MOD) % MOD;

}


int main(){
    cin >> n >> k;
    
    if(n == 1){
        cout << "1\n";
        return 0;
    }

    memset(b, -1, sizeof(b));

    for(int i = 0; i <= n-k; i++) cin >> a[i];

    for(int i = 0; i < n-k; i++){
        if(a[i] < a[i+1]){
            b[i] = 0;
            b[i+k] = 1;
        }
        if(a[i] > a[i+1]){
            b[i] = 1;
            b[i+k] = 0;
        }

        if(a[i] == a[i+1] && b[i] != -1){
            b[i+k] = b[i];
        }
    }


    int cnt = 0;
    int r = 0;

    for(int i = n-k; i < n; i++){
        if(b[i] == -1) cnt++;
        if(b[i] == 1) r--;
    }


    cout << nCrModPFermat(cnt,a[n-k]+ r) << "\n";

   
    


}