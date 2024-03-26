#include <bits/stdc++.h>
#include <iostream>



using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt = 0;

        while(n--){
            int x; cin >> x;

            if(x & 1) cnt++;
        }

        cout << (!(cnt & 1) ? "YES\n" : "NO\n");
    }
}