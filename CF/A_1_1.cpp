#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = "." + s;

        int cnt = 0;

        int a = 0;
        int b = 0;

        for(int i = 1; i <= n; i++) cnt += (s[i] - '0');

        for(int i = 1; i <= n-2; i++){
            if(s[i] == '1' && s[i+1] == '0' && s[i+2] == '1'){
                s[i+1] = '1';
                a++;
            }
        }


        int i = 1;

        while(i <= n){
            while(i <= n && s[i] == '0') i++;

            int sz = 0;
            while(i <= n && s[i] == '1'){
                sz++;
                i++;
            }

            if(sz < 3) continue;

            b += sz / 2 - !(sz&1);
            i++;
        }

        
        cout << cnt-b+a << " " << cnt+a << "\n";
        

        
    }
}