#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s,t; cin >> s >> t;

        while(t.size() > s.size()){
            if(t.back() == 'A') t.pop_back();
            else{
                t.pop_back();
                reverse(t.begin(), t.end());
            }
        }

        cout << (s == t ? "YES\n" : "NO\n");
    }
}