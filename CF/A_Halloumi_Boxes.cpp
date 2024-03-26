#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        

        int last = 0;
        bool flag = 1;
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x < last) flag = 0;
            

            last = x;
        }

        if(k > 1){
            cout << "YES\n";
            continue;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}