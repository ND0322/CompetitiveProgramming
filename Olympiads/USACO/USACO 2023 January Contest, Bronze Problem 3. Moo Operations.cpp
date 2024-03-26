#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int ans = 1e9;
        for(int i = 0; i < s.size()-2; i++){
            if(s[i+1] != 'O') continue;

            ans = min(ans, (s[i] != 'M') + (s[i+2] != 'O'));
        }

        cout << (ans == 1e9 ? -1 : ans + (int)s.size()-3) << "\n";
    }
}