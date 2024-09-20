#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];


        bool flag = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++) flag |= gcd(a[i], a[j]) <= 2;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}