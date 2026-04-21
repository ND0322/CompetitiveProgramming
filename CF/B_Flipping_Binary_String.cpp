#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
equivalent to setting x to x ^ ((1<<n)-1) ^ (1<<i)

if there are even number of 1s we can do that 

101100
000011

1111

*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ans.push_back(i+1);
        }

        if(((int)(ans.size()) & 1) && (n & 1)){
            cout << "-1\n";
            continue;
        }
        if(((int)(ans.size()) & 1)){
            vector<int> ans2;

            for(int i = 0; i < n; i++){
                if(s[i] == '0') ans2.push_back(i+1);
            }

            cout << ans2.size() << "\n";
            for(int i : ans2) cout << i << " ";
            cout << "\n";
        }
        else{
            cout << ans.size() << "\n";

            if(ans.empty()) continue;

            for(int i : ans) cout << i << " ";
            cout << "\n";
        }



    }
}