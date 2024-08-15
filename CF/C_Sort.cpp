#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, q, freq[MAXN][26][2];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        string s,t; cin >> s >> t;

        for(int i = 1; i <= n; i++) memset(freq[i], 0, sizeof(freq[i]));
    
        

        for(int i = 1; i <= n; i++){
            freq[i][s[i-1] - 'a'][0]++;
            freq[i][t[i-1] - 'a'][1]++;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++){
                freq[i][j][0] += freq[i-1][j][0];
                freq[i][j][1] += freq[i-1][j][1];
            }
        }

        while(q--){
            int l,r; cin >> l >> r;

            int a = 0;


            for(int i = 0; i < 26; i++) a += max(freq[r][i][0] - freq[l-1][i][0] - (freq[r][i][1] - freq[l-1][i][1]), 0);

            cout << a << "\n";


        }
    }

}