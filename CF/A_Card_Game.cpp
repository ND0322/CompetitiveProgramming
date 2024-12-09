#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, a, b; cin >> n >> a >> b;

        int mx = 0;
        bool flag = 0;

        for(int i = 0; i < a; i++){
            int x; cin >> x;

            mx = max(mx, x);
        }

        for(int i = 0; i < b; i++){
            int x; cin >> x;

            mx = max(mx, x);
            if(mx == x) flag = 1;
        }

        cout << (flag ? "NO\n" : "YES\n");
    }
}