#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    string s; cin >> s;

    int a = count(s.begin(), s.end(), 'o');
    int b = count(s.begin(), s.end(), '-');

    if(!a){
        cout << "YES\n";
        return 0;
    }

    cout << (b % a ? "NO\n" : "YES\n");
}