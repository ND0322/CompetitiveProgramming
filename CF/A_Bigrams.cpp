#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(x >= 3) cnt1++;
            else if(x >= 2) cnt2++;
        }

        if(cnt1){
            cout << "YES\n";
            continue;
        }

        if(cnt2 >= 2){
            cout << "YES\n";
            continue;
        }


        cout << "NO\n";
    }
}