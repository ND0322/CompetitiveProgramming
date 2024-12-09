#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        if(s[0] == '1' || s[n-1] == '1'){
            cout << "YES\n";
            continue;
        }

        bool flag = 0;

        for(int i = 0; i < n-1; i++) flag |= (s[i] == s[i+1] && s[i] == '1');

        cout << (flag ? "YES\n" : "NO\n");
    }
}