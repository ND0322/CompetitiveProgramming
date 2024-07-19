#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
0 1
1100 0100
111001
100101
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        //smallest bit that doesnt match

        long long cur = 1;

        while(cur <= max(x,y)){
            if((x & cur) != (y&cur)){
                cout << cur << "\n";
                break;
            }
            cur<<=1;
        }
    }
}