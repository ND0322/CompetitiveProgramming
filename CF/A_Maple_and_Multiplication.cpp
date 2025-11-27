#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        if(x == y){
            cout << "0\n";
            continue;
        }

        if(max(x,y) % (min(x,y)) == 0){
            cout << "1\n";
            continue;
        }

        cout << "2\n";
    }
}