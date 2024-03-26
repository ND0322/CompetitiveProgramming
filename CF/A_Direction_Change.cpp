#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;


        if(x > y) swap(x,y);

        if(x == 1){
            if(y <= 2){
                cout << y-1 << "\n";
                continue;
            }

            cout << "-1\n";
            continue;
        }

        cout << 2*y-2-((x+y)&1) << "\n";
    }
}