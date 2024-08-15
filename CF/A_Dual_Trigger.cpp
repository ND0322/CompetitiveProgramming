#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin>> n;

        string s; cin >> s;

        int cnt = 0;

        //must be even and its not just 1 11

        for(int i = 0; i < n; i++) cnt += (s[i] - '0');

        int check = 0;

        for(int i = 0; i < n-1; i++){
            if(s[i] == '1' && s[i+1] == '1') check++;
            

        }

        if(check == 1 && cnt == 2){
            cout << "NO\n";
            continue;
        }

        cout << (!(cnt&1) ? "YES\n" : "NO\n");
    }
}