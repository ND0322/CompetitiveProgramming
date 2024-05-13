#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int a = -1;
        int b = -1;

        bool ans = 1;

        for(int i = 0; i < n; i++){
            int c,d; cin >> c >> d;

            if(c < a || d < b) ans = 0;
            if(c-a < d-b) ans = 0;

            a = c;
            b = d;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}