#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;


        vector<bool> a(n+1);
        vector<bool> b(n+1);

        for(int i = 1; i <= n - k + 1; i++){
            char c; cin >> c;

            a[i] = (c == '1');
        }


        /*
        r2 = r1 + b2 - b1
        r2 - r1 + b1 = b2

        r2 ^ r1 ^ b1 = b2
        all things of the form i + nK
        actually amortizes nicely so it doesnt matter 
        */

        int mn = 1e9;

        int ans = 0;

        for(int i = 1; i <= k; i++){

            int j = i;

            bool cur = 0;
            int opt1 = 0;
            while(j+k <= n){
                cur ^= (a[j] ^ a[j+1]);
                if(cur) opt1++;
                j += k;
            }

            j = i;
            cur = 1;
            int opt2 = 1;

            while(j+k <= n){
                cur ^= (a[j] ^ a[j+1]);
                if(cur) opt2++;
                j += k;
            }


            if(opt1 < opt2){
                b[i] = 0;
                ans += opt1;
                mn = min(mn, opt2 - opt1);
            }
            else{
                b[i] = 1;
                ans += opt2;

                mn = min(mn, opt1 - opt2);
            }
        }
        

        bool flag = 0;

        for(int i = 1; i <= k; i++) flag ^= b[i];

        if(flag != a[1]) ans += mn;

        cout << ans << " ";

        mn = -1e9;

        ans = 0;

        for(int i = 1; i <= k; i++){

            int j = i;

            bool cur = 0;
            int opt1 = 0;
            while(j+k <= n){
                cur ^= (a[j] ^ a[j+1]);
                if(cur) opt1++;
                j += k;
            }

            j = i;
            cur = 1;
            int opt2 = 1;

            while(j+k <= n){
                cur ^= (a[j] ^ a[j+1]);
                if(cur) opt2++;
                j += k;
            }


            if(opt1 > opt2){
                b[i] = 0;
                ans += opt1;
                mn = max(mn, opt2 - opt1);
            }
            else{
                b[i] = 1;
                ans += opt2;

                mn = max(mn, opt1 - opt2);
            }
        }
        

        flag = 0;


        for(int i = 1; i <= k; i++) flag ^= b[i];

        if(flag != a[1]) ans += mn;

        cout << ans << "\n";

        
    }
}