#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int x = 0;

        bool flag = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            x ^= a[i];
        }

        for(int i = 1; i <= n; i++){
            if(a[i] == x^a[i]){
                flag = 1;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}