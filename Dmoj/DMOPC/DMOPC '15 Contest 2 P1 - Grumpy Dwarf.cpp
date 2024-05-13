#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    int ans = 0;
    int sw = 0;
    int bars = n;
    while(1){
        ans += bars;
        sw += bars;
        bars = sw/k;
        sw = sw%k;

        if(bars == 0){
            cout << ans << "\n";
            return 0;
        }
        
    }
}