#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e7+5;

int ans[MAXN];
bool prime[MAXN];

vector<int> primes;

//use ulimit -s unlimited

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    memset(prime, 1, sizeof(prime));

    for(int i = 2; i*i <= MAXN; i++){
        if(prime[i]){
            primes.push_back(i);
            for(int p = i*i; p <= MAXN; p += i) prime[p] = 0;
        }
    }

    //only need to check prime - 2 
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 1; i < MAXN; i++){
        if(!prime[i]){
            ans[i] = ans[i-1];
            continue;
        }

        if(i == 5) ans[i]++;

        ans[i] += ans[i-1] + prime[i-2];
    }
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        cout << "Case #" << _ << ": " << ans[n] << "\n";
    }
}