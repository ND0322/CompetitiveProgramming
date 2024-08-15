#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int pref[MAXN], suf[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        /*
        x..xxxx
        ..x....
        */

        int n; cin >> n;

        string s[2];

        cin >> s[0];
        cin >> s[1];

        //x.x and check that the areas are good
        //check that suffix has .
        //check that prefix has .

        suf[n+1] = 0;

        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + (s[0][i-1] == '.') + (s[1][i-1] == '.');
        for(int i = n; i >= 1;i --) suf[i] = suf[i+1] + (s[0][i-1] == '.') + (s[1][i-1] == '.');

        int cnt = 0;

        for(int i = 0; i < n-2; i++){
            if(s[0][i] == 'x' && s[0][i+1] == '.' && s[0][i+2] == 'x'){
                cnt += (bool)(pref[i+1] && suf[i+3]);
            }
        }

        for(int i = 0; i < n-2; i++){
            if(s[1][i] == 'x' && s[1][i+1] == '.' && s[1][i+2] == 'x'){
                cnt += (bool)(pref[i+1] && suf[i+3]);
            }
        }

        cout << cnt << "\n";
        





    }
}