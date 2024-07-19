#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        int tot = a+b+c;

        if(tot&1){
            cout << "-1\n";
            continue;
        }

        tot>>=1;

        cout << min(tot, a+b) << "\n";

    }
}