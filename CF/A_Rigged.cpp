#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){


    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int x,y;


        bool flag= 1;

        for(int i = 0; i < n; i++){
            int a,b; cin >> a >> b;

            if(!i){
                x = a;
                y = b;
                continue;
            }

            if(a >= x && b >= y){
                cout << "-1\n";
                flag = 0;
                break;
            }
        }

        if(flag){
            cout << x << "\n";
        }
    }
}