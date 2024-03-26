#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
2 5
2^2 * 5
3 * 2
*/



int main(){
    int tt; cin >> tt;

    while(tt--){
        int a, b, n; cin >> a >> b >> n;

        int cnta = 1;
        int cntb = 1;
        
        int cur = a;

        while(cur <= n){
            cnta+=!(n % cur);
            cur *= a;
        }

        cur = b;
        while(cur <= n){
            cntb+=!(n % cur);
            cur *= b;
        }

        cout << cnta << " " << cntb << "\n";

        cout << cnta * cntb << "\n";

    }



}