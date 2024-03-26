#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int cnt = 0;

        if(s[0] != 'a') cnt++;
        if(s[1] != 'b') cnt++;
        if(s[2] != 'c')cnt++;

        if(cnt > 2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}