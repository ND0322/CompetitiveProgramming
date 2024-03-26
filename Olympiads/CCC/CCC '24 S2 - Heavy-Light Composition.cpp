#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int n;

map<char,int> freq;

void solve(){
    string s; cin >> s;


    freq.clear();

    for(char c : s) freq[c]++;

    for(int i = 0; i < n-1; i++){
       
        if((bool)(freq[s[i]]-1) == (bool)(freq[s[i+1]]-1)){
            cout << "F\n";
            return;
        }
    }

    cout << "T\n";
}

int main(){
    int tt; cin >> tt >> n;

    while(tt--){

        solve();
        
    }
}