#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        bool flag = 1;

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '0') cnt++;
        }

        if(cnt > n-cnt){
            cout << "YES\n";
            continue;
        }

        for(int i = 0; i < n-1; i++){
            if(s[i] == '0' && s[i+1] == '0'){
                flag = 0;
                break;
            }
            if(s[i] == '0' && s[i+1] == '1'){
                flag = 0;
                break;
            }

            if(s[i] == '1' && s[i+1] == '0'){
                flag = 0;
                break;
            }
        }

        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
}