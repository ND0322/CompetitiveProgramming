#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string f(string s){
    string ans = "";

    int i = 0;

    int n = s.size();

    while(i < n){
        int l = i;

        while(i < n && s[i] == s[l]) i++;

        ans += to_string(i-l);
        ans += s[l];
    }

    return ans;
}

int main(){
    int n; cin >> n;

    string s; cin >> s;

    while(n--){
        s = f(s);
    }

    cout << s << "\n";
}