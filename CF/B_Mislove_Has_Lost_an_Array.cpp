#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, l, r; cin >> n >> l >> r;


    //min is take every from 2^0 to 2^l and 2^l n-l time
    //2^0 + 2^1 + 2^2
    //3 + 2 * 4
    //1 2 4 8 

    cout << (1<<l)-1 + (n-l) << " ";
    cout << (1<<r)-1 + (n-r) * (1<<(r-1)) << "\n";

}