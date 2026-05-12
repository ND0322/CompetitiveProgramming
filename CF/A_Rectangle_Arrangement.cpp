#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx[2] = {0,0};

        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            mx[0] = max(mx[0], x);
            mx[1] = max(mx[1], y);
        }

        cout << mx[0] * 2 + mx[1] * 2 << "\n";



    }
}