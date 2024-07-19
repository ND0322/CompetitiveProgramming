#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        bool act = 0;

        int cnt[2] = {0,0};

        string s; cin >> s;

        for(int i = 0; i < n; i++){

            bool x = s[i] - '0';
            if(act && x){
                cnt[0]++;
                act = 0;
            }

            if(!act && !x) act = 1;
            if(x) cnt[1]++;
        }

        cnt[0] += act;

        cout << (cnt[1] > cnt[0] ? "YES\n" : "NO\n");


    }
}