#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = '.' + s + s;

        int cur = 0;


        if(s[1] == '0') cur = 1;

        int ans = 0;
        for(int i = 2; i <= 2*n; i++){
            if(s[i] == '0') cur++;
            else if(s[i] == '1') cur = 0;

            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }
}