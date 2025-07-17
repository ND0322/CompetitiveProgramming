#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = "." + s;

        vector<int> pcnt(27, 0), scnt(27, 0);

        for(int i = 1; i <= n; i++) scnt[s[i] - 'a']++;
        
        
        pcnt[s[1] - 'a']++;
        scnt[s[1] - 'a']--;


        bool flag = 0;

        for(int i = 2; i < n; i++){
            scnt[s[i] - 'a']--;
            if(pcnt[s[i] - 'a'] || scnt[s[i] - 'a']){
                flag = 1;
                break;
            }

            pcnt[s[i] - 'a']++;
        
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}