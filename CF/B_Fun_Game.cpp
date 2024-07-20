#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;
        string t; cin >> t;

        bool ans = 1;


        for(int i = 0; i < n; i++){
            if(s[i] == '1') break;

            ans &= (!(s[i] == '0' && t[i] == '1'));
        }

        cout << (ans ? "YES\n" : "NO\n");
        
    }
}