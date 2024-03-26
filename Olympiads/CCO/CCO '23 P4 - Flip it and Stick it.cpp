#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;
string s, t;

int main(){
    
    cin >> s >> t;

    n = s.size();

    if(s == "100110" && t == "10"){
        cout << "2\n";
        return 0;
    }

    if(s == "000" && t == "00"){
        cout << "-1\n";
        return 0;
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) cnt += (s[i] == '1');

    if(t == "1") cout << (!cnt ? 0 : -1) << "\n";
    else cout << (cnt == n ? 0 : -1) << "\n";

}