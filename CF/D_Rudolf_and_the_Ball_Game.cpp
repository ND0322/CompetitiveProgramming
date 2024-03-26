#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m, id; cin >> n >> m >> id;

        vector<bool> can(n);

        can[id-1] = 1;

        for(int j = 0; j < m; j++){
            int x; cin >> x;

            char c; cin >> c;

            vector<bool> tmp(n+1);

            for(int i = 0; i < n; i++){
                if(!can[i]) continue;
                if(c != '0') tmp[(i-x+n)%n] = 1;
                if(c != '1') tmp[(i+x)%n] = 1;
            }

            can.swap(tmp);
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(can[i]) ans.push_back(i+1);
        }

        cout << (int)ans.size() << "\n";
        for(int i : ans) cout << i << " ";
        cout << "\n";

    }
}