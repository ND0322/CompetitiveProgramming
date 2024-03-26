#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int ans = 1e9;

    int n; cin >> n;


    for(int i = 0; i <= sqrt(n); i++){
        if(!(n % i)) ans = min(ans, 2*i + 2*(n/i));
    }

    cout << ans << "\n";
}