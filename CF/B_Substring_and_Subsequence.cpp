#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string a; cin >> a;
        string b; cin >> b;

        int n = a.size();
        int m = b.size();

        int ans = 1e6;
        for(int i = -1; i < m; i++){
            string s = b.substr(i+1);
            int j = 0;

            int cnt = 0;
            for(char c : s){
                while(j < n && a[j] != c) j++;
                if(j == n) break;
                cnt++;
                j++;
            }

            ans = min(i + 1 + n + (int)s.size()-cnt, ans);
        }

        cout << ans << "\n";


    }
}