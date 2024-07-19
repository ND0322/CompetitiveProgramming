#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int n = s.size();

        int l = -1;
        int r = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(l == -1) l = i;
                r = max(r, i);
            }
        }

        if(l == r){
            cout << "0\n";
            continue;
        }

        int cnt = 0;

        for(int i = l; i <= r; i++) cnt += (s[i] == '0');

        cout << cnt << "\n";

    }
}