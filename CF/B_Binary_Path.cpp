#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;

string s[2];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        cin >> s[0] >> s[1];

        int i = 0;
        int j = 0;


        //count split points
        int cnt = 0;
        string ans;

        while(i != n || j != 1){
            if(j == 1){
                ans += s[1][j];
                continue;
            }

            if(s[0][i] == '0' && s[1][i] == '1'){
                ans += '0';
                i++;
                continue;
            }

            if(s[0][i] == '1' && s[1][i] == '0'){
                j++;
                continue;
            }

            if(s[0][i] == s[1][i]){
                ans += s[1][j];
                i++;
            }
        }

    }
}