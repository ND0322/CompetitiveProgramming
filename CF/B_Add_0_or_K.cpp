#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
for odd k we can simply use parity
*/

#define int long long

const int MAXN = 1e6+5;
bool prime[MAXN];

vector<int> primes;

int32_t main(){
    int tt; cin >> tt;

    memset(prime, 1, sizeof(prime));
    for(int p = 2; p * p < MAXN; p++){
        if(prime[p]){
            primes.push_back(p);
            for(int j = p * p; j < MAXN; j += p) prime[j] = 0;
        }
    }


    prime[0] = 0;
    prime[1] = 0;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int b = 2;

        for(int i : primes){
            if(k%i){
                b = i;
                break;
            }
        }

        for(int i = 1; i <= n; i++){
            while(a[i] % b) a[i] += k;
        }

        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";

    }
}