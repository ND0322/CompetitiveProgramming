#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int n = s.size();

        int cnt = 0;
        for(int i =0 ; i < n-1; i++){
            if(s[i] == s[i+1]) cnt++;
        }

        cout << (cnt <= 2 ? "YES\n" : "NO\n");
    }
}