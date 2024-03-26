#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string ans = "zzz";
        for(int i = 1; i <= 26; i++){
            for(int j = 1; j <= 26; j++){
                for(int k = 1; k <= 26; k++){
                    if(i + j + k != n) continue;
                    string cur = "";
                    cur += (char)(i + 'a' - 1);
                    cur += (char) (j + 'a' - 1);
                    cur += (char) (k + 'a' - 1);
                    
                    ans = min(ans,cur);
                }
            }
        }

        cout << ans << "\n";
    }
}