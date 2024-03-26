#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int cnt = 0;

        vector<int> ones;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                cnt++;
                ones.push_back(i);
            }
        }

        if(cnt == s.size()-cnt){
            cout << "0\n";
            continue;
        }

        //swap with the leftmost available
        
        int i = 0;
        string ans = s;

        for(int j = 0; j < s.size() && i < ones.size(); j++){
            if(s[j] == '0'){
                ans[ones[i]] = '0';
                ans[j] = '1';
                i++;
            }
        }

      

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ans[i]){
                cout << s.size() - i << "\n";
                break;
            }
        }


    }
}