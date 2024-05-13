#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    string s; cin >> s;

    int cnt = 0;

    for(int i = 0; i < s.size(); i++) cnt += s[i] - '0';

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            cout << (s.size()-i-1)/2 + (cnt > 1|| ((s.size()-i-1) & 1)) << "\n";
            return 0;
        }
    }

    cout << "0\n";
}