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

        for(int j = 0; j < k-sz; j++){
            if(s.substr(j,j+sz) == t){
                for(int l = j; l < l+sz; l++) cnt[l]++;
            }
        }
    }

    for(int i = 0; i < k; i++) cout << cnt[i] << " ";
    cout << "\n";
}