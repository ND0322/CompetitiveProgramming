#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MAXB = 10;

#define int long long

int n; 

int cnt[1<<MAXB];

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        set<char> c;

        for(int j = 0; j < s.size(); j++) c.insert(s[j]);

        vector<int> digits;
        for(char l : c) digits.push_back(l - '0');


        for(int j = 1; j < (1<<digits.size()); j++){
            int bits = 0;

            for(int k = 0; k < digits.size(); k++){
                if(!(j & (1<<k))) continue;
                bits += 1<<digits[k];
            }

            cnt[bits]++;
        }
    }

    int ans = 0;
    for(int i = 1; i < 1<<10; i++) ans += (cnt[i] * (cnt[i]-1))/2 * pow(-1, !(__builtin_popcount(i) & 1));

    cout << ans << "\n";
}