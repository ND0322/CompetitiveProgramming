#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;
        string t; cin >> t;

        int a = 0;
        int b = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1' && t[i] == '0') b++;
            if(s[i] == '0' && t[i] == '1') a++;
        }

        cout << a+b - min(a,b) << "\n";
    }
}