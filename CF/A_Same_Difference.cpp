#include <bits/stdc++.h>
#include <iostream>


using namespace std;
int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt = 0;

        string s; cin >> s;

        for(int i = 0 ; i < n; i++) cnt += s[i] == s[n-1];
        cout << n-cnt << "\n";
    }

}