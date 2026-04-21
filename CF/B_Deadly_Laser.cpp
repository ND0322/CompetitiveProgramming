#include <bits/stdc++.h>
#include <iostream>

using namespace std;




int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m, sx, sy,d; cin >> n >> m >> sx >> sy >> d;

        bool blocked[4] = {0,0,0,0};
        for(int i = 1; i <= m; i++){
            if(abs(sx - 1) + abs(sy - i) <= d) blocked[0] = 1;
            if(abs(sx - n) + abs(sy - i) <= d) blocked[1] = 1;
        }

        for(int i = 1; i <= n; i++){
            if(abs(sx - i) + abs(sy - 1) <= d) blocked[2] = 1;
            if(abs(sx - i) + abs(sy - m) <= d) blocked[3] = 1;
        }


        if(blocked[0] && blocked[1]){
            cout << "-1\n";
            continue;
        }

        if(blocked[0] && blocked[2]){
            cout << "-1\n";
            continue;
        }

        if(blocked[3] && blocked[2]){
            cout << "-1\n";
            continue;
        }

        if(blocked[1] && blocked[3]){
            cout << "-1\n";
            continue;
        }

        cout << n + m -2 << '\n';
        


    }
}