#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        set<string> e;
        string s; cin >> s;

        for(int i = 0; i < n-1; i ++){
            e.insert(s[i] + s[i+1]);
        }

        cout << e.size() << endl;
    }
}