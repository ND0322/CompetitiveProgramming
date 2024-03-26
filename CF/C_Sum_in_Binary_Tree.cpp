#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;

        long long ans = 0;

        while(n != 1){
            ans += n;
            
            n /= 2;
        }

        ans++;
        cout << ans << "\n";
    }
}