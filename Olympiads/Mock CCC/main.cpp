#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int k; cin >> k;

    string s; cin >> s;
    vector<int> cnt(k);

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string t; cin >> t;

        int sz = t.size();

        for(int j = 0; j <= k-sz; j++){
            if(s.substr(j,sz) == t){
                for(int l = j; l < j+sz; l++) cnt[l]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < k; i++) ans += (cnt[i] >= 2);
    cout << ans << "\n";
}