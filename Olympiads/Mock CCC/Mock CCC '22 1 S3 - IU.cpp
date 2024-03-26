#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    int ans = 0;

    string s; cin >> s;

    for(int i = 0; i < (2*n)-1; i++){
        if(s[i] == 'I' && s[i+1] == 'U') ans++;
    }

    cout << n-ans << "\n";
}