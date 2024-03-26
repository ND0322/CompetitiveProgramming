#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        string s,t;

        cin >> s;
        cin >> t;

        bool flag = 1;

        for(int i = 0; i < n-1; i++) flag &= (s[i] != s[i+1]);

        if(flag){
            cout << "YES\n";
            continue;
        }
        

        flag = 1;

        for(int i = 0; i < m-1; i++) flag &= (t[i] != t[i+1]);

        if(!flag){
            cout << "NO\n";
            continue;
        }

        flag = 1;

        for(int i = 0; i < n-1; i ++){
            if(s[i]==s[i+1] && (s[i]==t[0] || s[i+1]==t[m-1])){
                flag = 0;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }


}