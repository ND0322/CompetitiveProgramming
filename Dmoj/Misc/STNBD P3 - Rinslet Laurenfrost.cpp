#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int freq[30][2];

int main(){
    string s; cin >> s;
    string t; cin >> t;

    for(char c : s) freq[c - 'a'][0]++;
    for(char c : t) freq[c - 'a'][1]++;

    int ans = 0;
    for(int i = 0; i < 26; i++) ans += abs(freq[i][0] - freq[i][1]);
    cout << ans << "\n";

}

