#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        set<int, greater<int>> s;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            s.insert(x);
        }

        if(s.size() != n){
            cout << "-1\n";
            continue;
        }

        for(int i : s) cout << i << " ";
        cout << "\n";

        
    }
}