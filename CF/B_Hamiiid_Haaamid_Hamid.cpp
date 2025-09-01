#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//split range in 2

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        string s; cin >> s;

        s = "." + s;

        int l = 0;
        int r = 0;
        for(int i = 1; i < k; i++){
            if(s[i] == '#') l = i;
        }

        for(int i = n; i > k; i--){
            if(s[i] == '#') r = i;
        }

        if(l == 0 && r== 0){
            cout << "1\n";
            continue;
        }

        if(l == 0 || r == 0){
            cout << min(k, n-k+1) << "\n";
            continue;
        }
        cout << 1 + (int)log2(r-l+1) << "\n";

    }
}