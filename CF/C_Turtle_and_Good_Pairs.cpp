#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        vector<int> cnt(27);

        s = '.' + s;

        sort(s.begin(), s.end());

        int l = 1;
        int r = n;

        char last = '.';

        string ans = "";
        while(l <= r){
            if(last == s[l]){
                ans += s[r];
                last = s[r--];
            }
            else{
                ans += s[l];
                last = s[l++];
            }
        }

        cout << ans << "\n";
       

       





    }
}