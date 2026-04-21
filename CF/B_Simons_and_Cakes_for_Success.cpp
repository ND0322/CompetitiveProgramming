#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e9;

int prime[50000];



/*
upper bound is n 
k the number unique prime factors
*/

int main(){
    memset(prime, -1, sizeof(prime));
    for(int i = 1; i * i < MAXN; i++){
        if(prime[i] == -1){
            for(int j = i*i; j < MAXN; j += i) prime[i] = i;
        }
        prime[i] = i;
    }

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        set<int> primes;

        while(n != 1){
            
        }


    }
}