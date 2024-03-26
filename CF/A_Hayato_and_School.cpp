#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
odd odd odd
even even odd
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int a[3] = {-1,-1,-1};
        int b[2] = {-1,-1};

        int x = 0;
        int y = 0;
        for(int i = 1; i <= n; i++){
            int p; cin >> p;

            if(p&1 && x < 3) a[x++] = i;
            if(!(p&1) && y < 2) b[y++] = i;
        }

        if(x >= 3){
            cout << "YES\n";
            cout << a[0] << " " << a[1] << " " << a[2] << "\n";
            continue;
        }

        if(x && y >= 2){
            cout << "YES\n";
            cout << a[0] << " " << b[0] << " " << b[1] << "\n";
            continue;
        }

        cout << "NO\n";
    }
}