#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int ind = -1;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]) ind = i;
        }

        if(ind == -1) cout << s + (s[s.size()-1] == 'z' ? 'a' : 'z') << "\n";
        else cout << s.substr(0, ind+1) + (s[ind] == 'z' ? 'a' : 'z') + s.substr(ind+1) << "\n";
    }
}