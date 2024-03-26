#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b; cin >> a >> b;

        long long ans = 0;
        for(int i = 0; i < 3; i++){
            int x,y; cin >> x >> y;

            if(x == a) ans = (abs(y-b) * abs(y-b));
            else if(y == b) ans = (abs(x-a) * (abs(x-a)));
        }

        cout << ans << "\n";
    }
}