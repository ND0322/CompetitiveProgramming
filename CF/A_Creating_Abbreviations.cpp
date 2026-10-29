#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool has[30];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        memset(has, 0, sizeof(has));

        for(int i = 1; i <= n; i++){
            string s; cin >> s;

            has[s[0] - 'a']=1;
        }


        bool ans = 1;
        for(int i = 1; i <= k; i++){
            string s; cin >> s;

            for(int j = 0; j < s.size(); j++) ans &= has[s[j] - 'A'];
        }

        cout << (ans ? "YES\n" : "NO\n");
    
    }
}