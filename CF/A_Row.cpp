#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    string s; cin >> s;

    if(s == "0"){
        cout << "No\n";
        return 0;
    }

    if(s[n-2] == '0' && s[n-1] == '0'){
        cout << "No\n";
        return 0;
    }

    if(s[0] == '0' && s[1] == '0'){
        cout << "No\n";
        return 0;
    }

    for(int i = 0; i < n-1; i++){
        if(s[i] == '1' && s[i+1] == '1'){
            cout << "No\n";
            return 0;
        }
    }

    for(int i = 0; i < n-2; i++){
        if(s[i] == '0' && s[i+1] == '0' && s[i+2] == '0'){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}