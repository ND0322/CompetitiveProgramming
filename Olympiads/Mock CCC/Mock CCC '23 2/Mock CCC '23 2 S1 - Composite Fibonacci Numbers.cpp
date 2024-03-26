#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

bool fib[MAXN], prime[MAXN];

int main(){

    fill(prime,prime+100004, 1);
    int i = 1;
    int j = 0;

    while(i+j <= 100000){
        int tmp = i;

        i = i+j;
        j = tmp;

        fib[i] = 1;
    }

    for(int i = 2; i*i <= 100000; i++){
        if(prime[i]){
            for(int j = i*i; j <= 100000; j+=i) prime[j] = 0;
        }
    }

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        //cout << prime[n] << "\n";

        cout << (fib[n] && !prime[n] ? "YES\n" : "NO\n");
    }


}