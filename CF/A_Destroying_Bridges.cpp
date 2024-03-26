#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        if(k >= n-1){
            cout << "1\n";
            continue;
        }

        int cnt = n;
        n--;

        while(k >= n && n){
            cnt--;
            k -= n;
            n--;
        }

        cout << cnt << "\n";
    }
}