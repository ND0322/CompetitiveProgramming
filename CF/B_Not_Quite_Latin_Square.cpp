#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        for(int i = 0; i < 3; i++){
            int had = 0;

            bool flag = 0;

            for(int j = 0; j < 3; j++){
                char c; cin >> c;

                if(c == '?'){
                    flag = 1;
                    continue;
                }
                had +=  c-'A'+1;
            }

            //cout << had << "\n";

            if(flag) cout << (char)(5-had+'A') << "\n";
        }
    }
}