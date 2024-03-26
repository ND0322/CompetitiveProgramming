#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        int l = 1e9;
        int r = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'B'){
                l = min(l,i);
                r = max(r,i);
            }
        }

        cout << r-l+1 << "\n";
    }
}