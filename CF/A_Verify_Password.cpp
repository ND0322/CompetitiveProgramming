#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        int lo = 1e9;
        int hi = -1;

        vector<int> a,b;

        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                lo = min(lo, i);
                a.push_back(s[i]);
            }
            else{
                hi = max(hi, i);
                b.push_back(s[i]);
            }
        }

        if(lo < hi){
            cout << "NO\n";
            continue;
        }

        cout << (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end()) ? "YES\n" : "NO\n");
    }
}