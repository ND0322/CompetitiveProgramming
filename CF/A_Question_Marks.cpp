#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt[4] = {0,0,0,0};

        string s; cin >> s;
        int k = 0;
        for(int i = 0; i < n*4; i++){
            if(s[i] == '?'){
                k++;
                continue;
            }

            cnt[s[i] - 'A']++;
        }

        int ans = 0;

        ans += min(n, cnt[0]);
        ans += min(n, cnt[1]);
        ans += min(n, cnt[2]);
        ans += min(n, cnt[3]);



        cout << ans << "\n";

        
    }
}