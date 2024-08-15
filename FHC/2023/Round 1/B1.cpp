#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int p; cin >> p;
        
        vector<int> ans;

        int sm = 0;

        for(int i = 2; i * i <= p; i++){
            while(p%i == 0){
                ans.push_back(i);
                sm += i;
                p /= i;
            }
        }

        if(p > 1){
            ans.push_back(p);
            sm += p;
        }

        if(sm > 41){
            cout << "Case #" << _ << ": -1\n";
            continue;
        }

        

        for(int i = 0; i < 41 - sm; i++) ans.push_back(1);

        cout << "Case #" << _ << ": ";

        cout << ans.size() << " ";

        for(int i : ans) cout << i << " ";
        cout << "\n";

    }
}
