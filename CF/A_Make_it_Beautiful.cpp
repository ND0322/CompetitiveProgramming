#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int>a(n);

        pair<int,int> mx = {0,-1};
        pair<int,int> mn = {1e9,-1};

        for(int i = 0; i < n; i++){
            cin >> a[i];

            mn = min(mn, {a[i], i});
            mx = max(mx, {a[i], i});
        }

        if(mn.first == mx.first){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        cout << mx.first << " " << mn.first << " ";

        
        for(int i = 0; i < n; i++){
            if(i != mn.second && i != mx.second) cout << a[i] << " ";
        }

        cout << "\n";

        
    }
}