#include <bits/stdc++.h>    
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        string s; cin >> s;

        vector<int> freq(30);

        for(int i = 0; i < n; i++) freq[s[i] - 'A']++;

        int ans = 0;

        for(int i = 0; i < 7; i++) ans += max(m - freq[i],0);

        cout << ans << "\n";


    }
}