#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

bool prime[MAXN];



int main(){
    for(int i = 1; i < MAXN; i++) prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i*i < MAXN; i++){
        if(prime[i]){
            for(int j = i*i; j < MAXN; j += i) prime[j] = 0;
        }
    }


    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        cout << (prime[n+1] ? "YES\n" : "NO\n");
    }
}