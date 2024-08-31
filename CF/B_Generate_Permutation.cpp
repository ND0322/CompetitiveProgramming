#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n&1){
            for(int i = 1; i <= n; i+=2) cout << i << " ";
            for(int i = n-1; i >= 2; i-=2) cout << i << " ";
            cout << "\n";
        }
        else{
            cout << "-1\n";
            continue;
        }
    }
}