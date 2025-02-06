#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2005;
const int MOD = 1e9+7;

int n, fact[MAXN];

unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
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
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main(){
    cin >> n;

    fact[0] = 1;

    for(int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;

    long long ans = 0;
    for(int i = 0; i <= n; i++){
      
        ans = (ans + (nCrModPFermat(n,i,MOD) * nCrModPFermat(n,i,MOD)) % MOD) % MOD;
    }

    cout << ans << "\n";


}