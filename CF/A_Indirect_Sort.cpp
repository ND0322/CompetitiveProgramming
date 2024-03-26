#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        bool flag = 1;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(i == 1 && x != 1) flag = 0;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}