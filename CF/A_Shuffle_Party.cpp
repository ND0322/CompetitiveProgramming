#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
goes to 2 first
then 4
then 8
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n == 1){
            cout << "1\n";
            continue;
        }

        long long ans = 1;

        for(int i = 0; i < floor(log2(n)); i++) ans <<=1;
        cout << ans << "\n";
    }
}