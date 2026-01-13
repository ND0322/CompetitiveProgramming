#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int cnt = 0;

        for(int i = 0; i < s.size(); i++) cnt += (s[i] == 'Y');
            
        

        cout << (cnt < 2 ? "YES\n" : "NO\n");
    }
}