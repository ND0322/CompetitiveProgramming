#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        vector<bool> cnt(n);
        

        for(int i = 2; i < n; i++) cnt[i] = (s[i] == 'p' && s[i-1] == 'a' && s[i-2] == 'm');    
        for(int i = 0; i < n-2; i++) cnt[i] = cnt[i] | (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e');

        int ans = 0;

        for(int i = 0; i < n; i++) ans += cnt[i];

        cout << ans << "\n";
    }
}