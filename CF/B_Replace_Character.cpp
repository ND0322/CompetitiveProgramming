#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int freq[30], ind[30], n;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        memset(freq, 0, sizeof(freq));
        memset(ind, 0, sizeof(ind));

        string s; cin >> s;

        for(int i = 0; i < n; i++){
            char c = s[i];

            freq[c-'a']++;
            ind[c-'a'] = i;
        }

        pair<int,int> mx = {0, -1}, mn = {1e9, -1};

        for(int i = 0; i < 26; i++){
            if(!freq[i]) continue;
            mx = max(mx, {freq[i], i});
            mn = min(mn, {freq[i], i});
        }

        for(int i = 0; i < n; i++){
            if(ind[mn.second] == i){
                char c = mx.second + 'a';
                cout << c;
                continue;
            }

            cout << s[i];
        }

        cout << "\n";


    }
}