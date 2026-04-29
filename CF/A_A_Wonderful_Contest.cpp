#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    
    while(tt--){
        int n; cin >> n;
        
        bool flag = 0;

        for(int i =1; i <= n; i++){
            int x; cin >> x;

            flag |= (x == 100);
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}