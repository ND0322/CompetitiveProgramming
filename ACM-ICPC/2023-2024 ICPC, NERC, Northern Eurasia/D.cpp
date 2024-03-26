#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int b, n; cin >> b >> n;

        long long cur = 1;
        bool flag = 1;
        for(int i = 1; i <= n; i++){
            cur = (cur*b) % n;

            if(cur == 0){
                cout << "1 " << i << "\n";
                flag = 0;
                break;
            }
            if(cur == 1 % n){
                cout << "2 " << i << "\n";
                flag = 0;
                break;
            }
            if(cur == n-1){
                cout << "3 " << i << "\n";
                flag = 0;
                break;
            }
        }

        if(flag) cout << "0\n";

       


    }
}