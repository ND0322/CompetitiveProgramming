#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
1 and n must be s
no run of U with size more than 1 can exist 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int n = s.size();
        s = '.' + s;

        int ans = 0;
        if(s[1] == 'u'){
            s[1] = 's';
            ans++;
        }

        if(s[n] == 'u'){
            s[n] = 's';
            ans++;
        }

        int i = 1; 

        while(i <= n){
            int l = i;

            if(s[i] == 's'){
                i++;
                continue;
            }

            while(i < n && s[i+1] == 'u') i++;
            ans += (i-l+1)/2;
            i++;
        }

        cout << ans << "\n";
    }
}