#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
if x is at the front at time t
element x will first be at front at 3t - 1
then x will be at the front again in (t+1)/2 + 1 time 


*/

#define int long long

int32_t main(){

    int q; cin >> q;

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int x, tc; cin >> x >> tc;

            if(tc < 2 * x){
                cout << x << "\n";
                continue;
            }

            if(tc < 3*x){
                cout << x - (tc - 2*x + 1) << "\n";
                continue;
            }

            int tfront = 3*x-1;

            while(tfront + (tfront + 1) / 2 + 1 < tc) tfront += (tfront+1)/2 + 1;

            int move = (tc - tfront);
            

            cout << (tfront+1)/2+1 - move << "\n";


        }
        else{
            int pos, tc; cin >> pos >> tc;


        }
    }
}