#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int>a,g(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i < n; i++) g[i] = gcd(a[i], a[i+1]);


        



    }
}