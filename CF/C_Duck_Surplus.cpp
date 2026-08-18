#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long pmax = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(pmax <= x) pmax = x;
            else pmax += x;
        }

        cout << pmax << "\n";
    }
}