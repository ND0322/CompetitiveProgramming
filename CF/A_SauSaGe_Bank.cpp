#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long n,k; cin >> n >> k;


        cout << 2 * (k-1) + (1<<(n-k+1)) << "\n";
    }
}