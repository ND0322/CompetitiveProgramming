#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        int i = 0;

        int mx[2] = {0,0};
        int cnt[2] = {0,0};

        while(i < n){
            int cntt =0;

            char c = s[i];
            while(i < n && s[i] == c){
                i++;
                cntt++;
            }

            cnt[c == '1'] += cntt;
            mx[c=='1'] = max(mx[c=='1'],cntt);
        }

        cout << max({cnt[0] * cnt[1], mx[0] * mx[0], mx[1] * mx[1]}) << "\n";
    }
}