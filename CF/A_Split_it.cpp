#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        string s; cin >> s;

        if(n < 2*k+1){
            cout << "NO\n";
            continue;
        }

        bool flag = 1;
        for(int i = 0; i < k; i++) flag &= s[i] == s[n-i-1];

        cout << (flag ? "YES\n" : "NO\n");
    }
}