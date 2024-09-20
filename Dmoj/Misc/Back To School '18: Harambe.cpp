#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    string s; cin >> s;
    string t; cin >> t;
    cout << s << "\n";
    cout << t << "\n";

    int k; cin >> k;

    int cnt = 0;
    for(int i = 0; i < s.size(); i++) cnt += (s[i] != t[i] && s[i] != ' ' && t[i] != ' ');
    cout << (cnt <= k ? "Plagiarized" : "No plagiarism");


}