#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        string s; cin >> s;


        int cnt = 0;

        for(char c:s){
            if(c == '.') cnt++;
        }

        bool flag = 0;

        for(int i = 0; i < n-2; i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                //cout << "2\n";  
                flag = 1;
                break;
                
            }
        }


        if(flag) cout << "2\n";
        else cout << cnt << "\n";
    }
}