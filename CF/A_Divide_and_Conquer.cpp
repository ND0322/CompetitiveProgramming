#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int sm = 0;

        int mn = 1e9;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            sm ^= (x&1);
            
            bool s = x&1;
            int cnt = 0;

            while((x&1) == s){
                x>>=1;
                cnt++;
            }

            mn = min(mn, cnt);
            
        }

        if(!sm){
            cout << "0\n";
            continue;
        }

        cout << mn << "\n";
    }
}