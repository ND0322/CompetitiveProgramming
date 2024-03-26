#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> cnt;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        cnt.clear();

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j <= s.size(); j++){
                cnt.insert(s.substr(i,j));

                
            }
        }

        cout << cnt.size() << "\n";
    }
}