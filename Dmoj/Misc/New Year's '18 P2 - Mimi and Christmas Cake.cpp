#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;

bool prime[MAXN];

int main(){
    cin >> n;
    memset(prime, 1, sizeof(prime));

    prime[1] = 0;

    for(int x=  2; x*x <= 1e5; x++){
        if(prime[x]) for(int i = x*x; i <= 1e5; i+=x) prime[i] = 0;
    }

    int ans = 0;


    for(int i = 0; i < n; i++){
        int x; cin >> x;

        ans += prime[x];

    }

    cout << ans << "\n";
}